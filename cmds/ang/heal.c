// heal command..

inherit F_CLEAN_UP;
#include <ansi.h>

int main(object me, string str)
{
	object ob;
	if (!str) return notify_fail("格式：heal <某人ID>\n");
	ob = LOGIN_D->find_body(str);
	if (!ob) return notify_fail("咦... 有这个人吗?\n");
	tell_object(me, HIC"你念起长生咒：吗哩吗哩哄，吗哩吗哩哄！（天呐，这是哪国语言呀！）\n"NOR );
	tell_object(ob, HIY"你只觉一股清香沁入心肺，顿时所有的伤口都复原了，而且神采飞扬，神意清爽！看来是有人给你疗伤了。\n"NOR );
	ob->set_temp("nopoison", 1);
	ob->set("jingli",ob->query("max_jingli"));
	ob->set("eff_jingli",ob->query("max_jingli"));
	ob->set("eff_qi",ob->query("max_qi"));
	ob->set("qi",ob->query("max_qi"));
	ob->set("neili",ob->query("max_neili"));
	ob->set("douzhi",ob->query("max_douzhi"));
	write_file("/log/cmds/HEAL_PLAYER",sprintf("%s 为 %s 疗伤 on %s\n",
	this_player()->name(1),ob->name(1), ctime(time()) ));
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : heal <某人>


此指令可让你(你)将某人的所有状态恢复。
HELP
    );
    return 1;
}
