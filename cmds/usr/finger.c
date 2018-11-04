// finger.c

#include <ansi.h>

inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	object ob;
	
	if( !arg )
	{
		if( (int)me->query("jingli") < 50 )
			return notify_fail("你的精力不足。\n");
		if( !wizardp(me) )
			me->receive_damage("jingli", 50);
		write( FINGER_D->finger_all() );
	} else 
	{
		ob=find_player(arg);
		if( (int)me->query("jingli") < 15 )
			return notify_fail("你的精力不足。\n");
		if( !wizardp(me) )
			me->receive_damage("jingli", 15);
		write( FINGER_D->finger_user(arg) );
		if (ob&&me->visible(ob)&&(me!=ob))
		{
			if(!wizardp(me))
			{
				tell_object(ob,HIY"你不由得打了一个冷战...\n"NOR);
/*
				message("channel:chat", HIG +"【闲聊】啊....嚏...."+ 
					ob->query("name")+"打了一个大喷嚏...好爽啊.\n"NOR, users());
*/
			}
		}
	}
	return 1;
}

int help()
{
  write(@HELP
指令格式 : finger [使用者姓名]
 
这个指令, 如果没有指定使用者姓明, 会显示出所有正在线上玩家
的连线资料. 反之, 则可显示有关某个玩家的连线, 权限等资料.
 
see also : who
HELP
    );
    return 1;
}
 
