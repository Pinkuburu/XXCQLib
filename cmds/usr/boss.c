// TIE@FY3
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string msg;
	write(CLR);
	if(arg)
	{
		msg = read_file("/open/shit.txt");
		write(msg);
	}
	me->set_temp("block_msg/all",1);
message("channel:chat", HIW"【警铃】"+me->name(1)+"匆匆关上屏幕，回头就跑。看来是老板来了。\n"NOR,users());
	return 1;
}

int help(object me)
{
     write(@HELP
指令格式: boss <arg>

这个指令让你(玩家)在老板出现前一秒钟时将屏幕上所有的
中文消除，如果 <arg>不是零的话，本命令会在你的屏幕上
显示出一些文章。与此同时，你将受不到任何来自游戏的讯
息，直到你输入bossgone指令。

有关指令：bossgone
HELP
    );
    return 1;
}
