//		clone/linghou.c  writen by winder for sotw

inherit ITEM;
#include <ansi.h>

void create(object me,string arg)
{
	set_name(HIR "灵火" NOR, ({"huo"}));
        set("unit", "枚");
	set("long", "这是一枚江湖中用来紧急通讯和联络的火器。\n指令格式 : hu <某人>/<all>\n");
        setup();
}

void init()
{
        add_action("do_fire", "hu");
}

int do_fire(string arg)
{
	object me, who, *whose, where, wwhere;
	int i, mount;
	string name, family, wfamily;

	me = this_player();
	where = environment(me);
	name = (string) me->query("name");
	family = (string) me->query("family");

	if ((int) me->query("neili") < 20)
		return notify_fail(HIY"你内力不足以将灵火引燃！\n"NOR);

	if( !arg)
		return notify_fail("你要干什么？\n");
	else
	{
		if( arg == "all") 

//	需要查询如何判别没有门派 me->query("family") == "" 		//

			if ( me->query("family") == "" )
				return notify_fail(HIY"你不是任何帮派的弟子，没有同门师兄弟可以呼叫！\n"NOR);
			else
			{
				message_vision(HIR "\n$N自怀中取出一枚赤红色的灵火，运内力于指尖，扬手向空中弹去！\n" NOR, me);
				message_vision(HIR "\n灵火带着刺耳的尖叫声窜入云霄，爆裂开来化作一只鲜红的恶龙，久久仍不消散！\n" NOR, me);
				message_vision(HIR "\n不知师兄弟能不能及时赶到这里！\n" NOR, me);
				whose = users();
				for (i; i < sizeof(whose); i++)
				{	// Skip those users in login limbo.
					if( !environment(whose[i]) && !me->visible(whose[i]) )
						continue;
					else
					{
						wfamily = (string) whose[i] -> query("family");
						if ((family == wfamily) && (me != whose[i]))
//							tell_object(whose[i], HIR"\n你猛一抬头，发现" + (string)where->query("short")+ "的上空升起一条鲜红色的巨龙！\n\n看来有同门师兄弟" + (string)me->query("name") + "遇到危险了！\n" NOR);
							tell_object(whose[i], HIR"\n你猛一抬头，发现" + (string)where->query("short")+ "的上空升起一条鲜红色的巨龙！\n\n看来有同门师兄弟遇到危险了！\n" NOR);
						else
							continue;
					}
				}
				me->set("neili", me->query("neili")-20);
				destruct(this_object());
				return 1;
			}
		else
		{
			who = LOGIN_D->find_body(arg);
			if ( me == who)
				return notify_fail(HIY"自己呼叫自己，你有病吧！\n"NOR);
			if ( !who || !environment(who))
				return notify_fail(HIY"没有这个玩家或其未在线上！\n"NOR);
			else
			{
				wwhere = environment(who);
				if ( (string)where == (string)wwhere)
				{
					tell_object(me,HIY"就在身边，不用那么费劲吧！\n"NOR);
					return 1;
				}
				else
				{
					message_vision(HIR "\n$N自怀中取出一枚赤红色的灵火，运内力于指尖，扬手向空中弹去！\n" NOR, me);
					message_vision(HIR "\n灵火带着刺耳的尖叫声窜入云霄，爆裂开来化作一只鲜红的恶龙，久久仍不消散！\n" NOR, me);
					message_vision(HIR "\n不知" + (string)who->query("name") + "能不能及时赶到这里！\n" NOR, me);
					tell_object(who,HIR "\n你猛一抬头，发现" + (string)where->query("short")+ "上空升起一条鲜红的巨龙！\n\n看来" + (string)(me->query("name")) + "遇到危险需要你帮忙！\n" NOR);
//					tell_object(who,HIR "\n你猛一抬头，发现" + (string)where->query("short")+ "上空升起一条鲜红的巨龙！\n\n看来遇到危险需要你帮忙！\n" NOR);
					me->set("neili",me->query("neili")-20);
					destruct(this_object());
					return 1;
				}
			}
		}
	}
}

int help (object me)
{
	write(@HELP
指令格式 : hu <某人>/<all>
这个指令让你向任何玩家(或向自己帮派的所有人)求救。
HELP);
	return 1;
}
