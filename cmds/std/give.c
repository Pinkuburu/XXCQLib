// give.c
#include <ansi.h>
//modify by jackyboy @cctx 98/12/29 for quest type "寻" & "送"
#define CMDS_NICK "/cmds/usr/nick"
inherit F_CLEAN_UP;

int do_give(object, object, object);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
	object obj, who, *inv, obj2;
	int i, amount;

	if(!arg) return notify_fail("你要给谁什么东西？\n");

	if( sscanf(arg, "%s to %s", item, target)==2
	|| sscanf(arg, "%s %s", target, item)==2 );
	else return notify_fail("你要给谁什么东西？\n");

	if(!objectp(who = present(target, environment(me))) || !living(who))
		return notify_fail("这里没有这个人。\n");

	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )	
			return notify_fail("你身上没有这样东西。\n");
		if( obj->query("no_drop") )
			return notify_fail("这样东西不能随便给人。\n");
         if( who->query("env/no_accept"))
                 return notify_fail("对方现在不接受别人的馈赠。\n");
		if( !obj->query_amount() )	
			return notify_fail( obj->name() + "不能被分开给人。\n");
		if( amount < 1 )
			return notify_fail("东西的数量至少是一个。\n");
		if( amount > obj->query_amount() ) 
			return notify_fail("你没有那么多的" + obj->name() + "。\n");
		else if( amount == (int)obj->query_amount() )
			return do_give(me, obj, who);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			if (do_give(me, obj2, who))
				return 1;
			else {
				obj->set_amount((int)obj->query_amount() + amount);
				return 0;
			}
		}
	}

	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			do_give(me, inv[i], who);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("你身上没有这样东西。\n");
	return do_give(me, obj, who);
}

int do_give(object me, object obj, object who)
{
	if( obj->query("no_drop") )
		return notify_fail("这样东西不能随便给人。\n");
	if( !interactive(who) && !who->accept_object(me, obj) )
		return notify_fail("对方并不接受这样的东西。\n");
	if( who->query("env/no_accept"))
		return notify_fail("对方现在不接受别人的馈赠。\n");
	//因为部分代码不规范，会在accept_object里将obj destruct，所以增加此句
	if(!objectp(obj))
		return notify_fail("物品接受者代码不规范("+base_name(who)+".c)，请转告巫师！\n");
	//如果不值钱并且对方不是玩家则销毁该物品
	if( !userp(who)&&!obj->value() ) {
		message_vision("$N拿出" + obj->short() + "给$n。\n", me, who);
		destruct(obj);
		me->save();
		return 1;
	} 
	//如果成功递交物品则显示相关信息
	if( obj->move(who) )
	{
		message_vision("$N拿出一" + obj->query("unit") + obj->name() + "给$n。\n", me, who);
		me->save();
		return 1;
	}
	else 
	//如果不成功则判断对方是否是玩家，是则显示无法give，否则显示给出去了，但销毁该物品
	//用于处理npc负载超重的情况，但是如果是比较重要的物品的话可能会出现问题，只有靠写物品的
	//巫师多多注意些了。
	if(!userp(who))
	{
		message_vision("$N拿出" + obj->short() + "给$n。\n", me, who);
		//因为对方不是玩家，所以可以酌情提高其容量
		if((who->query_max_encumbrance()+2*obj->weight() )>0)//防止溢出
			who->set_max_encumbrance(who->query_max_encumbrance()+2*obj->weight());
		if(!obj->move(who))
		{
			if(userp(obj))
			{
				message_vision("$N一下子没接稳，$n滚了下来。\n",who,obj);
				obj->move(environment(who));
			}
			else
				destruct(obj);
		}
		return 1;
	}
	else
	{
		return notify_fail("对方已经无法接受你给的物品了！\n");
	}
}
int help()
{
write(@HELP
指令格式 : give <物品名称> to <某人>
      或 : give <某人> <物品名称>
 
这个指令可以让你将某样物品给别人, 当然, 首先你要拥有这样物品.
 
HELP
    );
    return 1;
}
