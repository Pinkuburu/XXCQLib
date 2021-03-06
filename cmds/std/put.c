// put.c

inherit F_CLEAN_UP;

int do_put(object, object, object);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
	object obj, dest, *inv, obj2;
	int i, amount;

	if(!arg) return notify_fail("你要将什么东西放进哪里？\n");

	if( sscanf(arg, "%s in %s", item, target)!=2 )
		return notify_fail("你要给谁什么东西？\n");

	dest = present(target, me);
	if( !dest || living(dest) ) dest = present(target, environment(me));
	if( !dest || living(dest) )
		return notify_fail("这里没有这样东西。\n");
	//JackyBoy如果有container属性或者is_container()调用返回1说明是容器类，可以放进去！
	if( dest->query("container")==0&&!dest->is_container())
		return notify_fail("不能放东西到"+dest->name()+"里的。\n");
	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("你身上没有这样东西。\n");
		if(!obj->query("no_drop"))
			return notify_fail("这样东西不能离开你。\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "不能被分开。\n");
		if( amount < 1 )
			return notify_fail("东西的数量至少是一个。\n");
		if( amount > obj->query_amount() )
			return notify_fail("你没有那么多的" + obj->name() + "。\n");
		else if( amount == (int)obj->query_amount() )
			return do_put(me, obj, dest);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			return do_put(me, obj2, dest);
		}
	}

	if(item=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if( inv[i] != dest ) do_put(me, inv[i], dest);
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("你身上没有这样东西。\n");
	return do_put(me, obj, dest);
}

int do_put(object me, object obj, object dest)
{
	if(obj==dest)
	{
		tell_object(me,"不能把"+obj->name()+"放到它自己里面！\n");
		return 1;
	}
	if( obj->query("no_drop"))
	{
		tell_object(me,obj->name()+"不能离开你！\n");
		return 1;
	}
	
	if( obj->move(dest) ) {
		message_vision( sprintf("$N将一%s%s放进%s。\n",
			obj->query("unit"), obj->name(), dest->name()),
			me );
		return 1;
	}
	else return 0;
}

int help()
{
write(@HELP
指令格式 : put <物品名称> in <某容器>
 
这个指令可以让你将某样物品放进一个容器，当然，首先你要拥有这样物品。
 
HELP
    );
    return 1;
}
