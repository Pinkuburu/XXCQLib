//inventory.c

#include <ansi.h>

inherit F_CLEAN_UP;
string total_inv(object*);
int main(object me, string arg)
{
	object *inv, ob;
	int opt;
	string str;
	//在这里解析开关
	opt=0;
	if(arg)
		sscanf(arg,"-%d %s",opt,arg);//opt不为0则表示要详细信息
	if( wizardp(me) && arg ) {
		ob = find_player(arg);
		if( !ob ) ob = find_living(arg);
		if( !ob ) ob = present(arg, environment(me));
	}

	if( !ob ) ob = me;

	inv = all_inventory(ob);
	if( !sizeof(inv) ) {
		write((ob==me)? "目前你身上没有任何东西。\n"
			: ob->name() + "身上没有携带任何东西。\n");
		return 1;
	}
	str=(ob==me)? "你": ob->name();
	str+="身上带著下列这些东西(负重"+
		(string)((int)ob->query_encumbrance() * 100/ (int)ob->query_max_encumbrance())+
		"%)：\n";
	str+=opt?implode(map_array(inv, "inventory_desc", this_object()), "\n"):total_inv(inv);
	me->start_more(str);
	return 1;
}

string total_inv(object* inv)
{
	mapping ni;//name&id就可分辨两个物件是否是同一个了，文件名是否相同不管他了
	mapping ni_unit;//用来保存ni里对应项的单位。
	object ob;
	string name,id,prop,str;
	int num;
	ni=([]);
	ni_unit=([]);//必须初始化
	foreach(ob in inv)
	{
		name=ob->name(1);
		id=ob->query("id");//不使用ob->parse_command_id_list();
		prop=name+"_"+id;//或者用name+"/"+id???
		num=ob->query_amount();
		if(num==0)
			num=1;
		if(undefinedp(ni[prop]))
		{
			ni[prop]=num;//统计数量
			if(!stringp(ni_unit[prop]=ob->query("base_unit")))//记录单位
				ni_unit[prop]=ob->query("unit");
			if(!stringp(ni_unit[prop]))
				ni_unit[prop]="些(单位不清!)";
			//还应该记录装备情况！或者两个类型的命令并存呢？
		}
		else
		{
			num=num+ni[prop];
			ni[prop]=num;
		}
	}
	//开始合并值！
	str="";
	foreach(prop in keys(ni))
	{
		if(sscanf(prop,"%s_%s",name,id)!=2)
		{
			log_file("inv" , "错误解析"+prop+"\n");
			continue;//如果有错误，跳过。
		}
		num=ni[prop];
		str+=chinese_number(num)+ni_unit[prop]+name+"("+id+")\n";
	}
	return str;
}

string inventory_desc(object ob)
{
	return sprintf("%s%s",
		ob->query("equipped")? HIC "□" NOR:"  ",
		ob->short()
	);
}

int help ()
{
        write(@HELP
指令格式: inventory [-num] [玩家ID]
 
可列出你(你)目前身上所携带的所有物品。
没有参数-num（num为非零数）表示只需要综合显示，否则表示需要详细显示！
玩家ID这个参数只有巫师可以使用！
注 : 此指令可以 " i " 代替。
 
HELP
);
        return 1;
}
