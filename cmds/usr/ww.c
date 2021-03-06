// who.c
// From ES2
// Modified by Java on Sep.14 1998

#include <ansi.h>
#include <net/dns.h>
#include <mudlib.h>
inherit F_CLEAN_UP;

int sort_user(object,object);
int help();

void create() { seteuid(getuid()); }

mixed main(object me, string arg, int remote)
{
	string name, str, *option;
	object *list, *ob, ob1;
	int i, ppl_cnt;
	int opt_long, opt_wiz, opt_party;
	if( arg )
	{
		option = explode(arg, " ");
		i = sizeof(option);
		while( i-- )
			switch(option[i])
			{
				case "-h": return help();
				case "-l": opt_long = 1;break;
				case "-w": opt_wiz = 1;break;
				case "-p": opt_party = 1;break;
				default:
					if(option[i][0]=='@' )
					{
						RWHO_Q->send_rwho_q(option[i][1..sizeof(option[i])],me, opt_long);
						write("网路讯息已送出，请稍候。\n");
						return 1;
					}
					ob1 = present(option[i], environment(me));
					if (!ob1) ob1 = find_player(option[i]);
					if (!ob1) ob1 = find_living(option[i]);
					if ((!ob1) && (option[i] =="me")) ob1=me;
					if (!ob1) return notify_fail("没有这个玩家或参数错误。\n指令格式 : who [-h] [-l] [-w] [-p] [<ID>]\n");
					me = ob1; opt_party = 1;
			}
	}
	str = HIW+CHINESE_MUD_NAME+NOR"目前";
	if(opt_party)
		if(me->query("family/family_name"))
			str += HIR+"("+me->query("family/family_name")+") "+NOR;
		else str += HIR + "(无门派) " + NOR;
	if ( opt_wiz )
		str += "巫师有：";
	else
		if ( opt_long ) str += "玩家有：";
		else str += "总人物有：";
	str += "\n─────────────────────────────────────\n";
	ob = filter_array(objects(), (: userp :));
	if (opt_party)
		ob = filter_array(ob, (: $1->query("family/family_name") ==	$2->query("family/family_name") :), me);
	list = sort_array(ob, (: sort_user :));
	ppl_cnt = 0;
	if( opt_long || opt_wiz)
	{
		i = sizeof(list);
		while ( i-- )
		{
			// Skip those users in login limbo.
			if( !environment(list[i]) ) continue;
			if( !wizardp(me) && !me->visible(list[i]) ) continue;
			if (opt_wiz&&!wizardp(list[i]) ) continue;
			if( interactive(list[i]) )
				ppl_cnt++;
			str = sprintf("%s%12s%s%s\n",str,RANK_D->query_rank(list[i]),
				interactive(list[i])?(query_idle(list[i]) > 120? HIG "*" NOR:" "):HIR "#" NOR,
				list[i]->short(1));
		}
	}
	else
	{
		i = sizeof(list);
		while ( i-- )
		{
			// Skip those users in login limbo.
			if ( !environment(list[i]) ) continue;
			if ( !wizardp(me) && !me->visible(list[i]) ) continue;
			name=interactive(list[i])?(query_idle(list[i])>120?HIG"*" NOR:" "):HIR "#" NOR;
			name = sprintf( "%s%-10s(%-11s│",name,list[i]->name(1),
					capitalize(list[i]->query("id"))+")");
			str = sprintf("%s%25s%s", str, name,ppl_cnt%3==2?"\n":"");
			//if (interactive(list[i]))
			ppl_cnt++;
		}
		if ( ppl_cnt%3 ) str += "\n";
	}
	str += "─────────────────────────────────────\n";
	str = sprintf("%s共有 %s 位使用者连线中，系统负担：%s\n "HIG"*"NOR" 表示发呆中，"HIR"#"NOR" 表示断线中。", str, CHINESE_D->chinese_number(sizeof(list)),
	query_load_average());
//      if( remote ) return str;
//      write(str + "\n");
	me->start_more(str);
	return 1;
}
int sort_user(object ob1, object ob2)
{
	string name1, name2;
	if( wiz_level(ob1) != wiz_level(ob2) )
		return wiz_level(ob2) - wiz_level(ob1);
	name1 = ob1->query("family/family_name");
	name2 = ob2->query("family/family_name");
	if (intp(name1)) name1 = "";
	if (intp(name2)) name2 = "";
	if (name1 > name2) return -1;
	if (name1 < name2) return 1;
	return (int)ob2->query("family/generation") - (int)ob1->query("family/generation");
}

int help()
{
	write("指令格式 : who [-h] [-l] [-w] [-p] [<ID>]
这个指令可以列出所有在线上的玩家及其等级。
-h 列出帮助屏幕。
-l 选项列出较长的讯息。
-p 只列出同门的玩家。
-w 只列出线上所有的巫师。
<ID> 列出<ID>代表玩家所属门派的玩家。
"HIG"*"NOR" 表示"HIG"发呆"NOR"中，"HIR"#"NOR" 表示"HIR"断线"NOR"中。
相关指令： finger");
    return 1;
}