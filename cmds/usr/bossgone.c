// TIE@FY3
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	me->delete_temp("block_msg/all");
	write(CLR);
	write("\n胖胖关心的问你：运气如何？被抓住了吗？下次小心呀！\n");
message("channel:chat", HIC"【警铃】"+me->name(1)+"得意洋洋地打开屏幕，看着老板在门外消失：拜拜了您哪。\n"NOR,users());
	return 1;
}

int help(object me)
{
     write(@HELP
指令格式: bossgone  

这个指令让你(玩家)在老板走后恢复正常的游戏。

有关指令：boss
HELP
    );
    return 1;
}
