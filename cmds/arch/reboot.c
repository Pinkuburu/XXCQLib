#include <ansi.h>
#include <net/daemons.h>

inherit F_CLEAN_UP;
int delay=0;

int main(object me)
{
	if( me != this_player(1) ) return 0;
	
	if( wiz_level(me) < wiz_level("(arch)") )
		return notify_fail("只有 (arch) 以上的巫师才能重新启动" + MUD_NAME + "\n");
	write("发出 Reboot 信息。\n");
	call_out("reboot", 1 );
	return 1;
}

int reboot()
{
	int i;
	object *u,link_ob;
	if( delay > 2 ) {
		message( "system", HIR "\n\n\n游戏重新启动，请稍候一分钟再 login 。\n\n\n" NOR, users() );
		if( find_object(DNS_MASTER) ) DNS_MASTER->send_shutdown();
		u=users();
		for(i=0; i<sizeof(u); i++) {
			if( !environment(u[i]) ) continue;
			u[i]->save();
			link_ob = u[i]->query_temp("link_ob");
			if( objectp(link_ob) ) link_ob->save();
		}
		shutdown(0);
	}
	else {
		delay ++;
		message( "system", 
			sprintf( HIR "%s告诉你：系统将在 %d 秒后重新启动，请 save 和 quit 。\n" NOR,
				MUD_NAME,
				(4-delay)*30), 
			users()
		);
		call_out("reboot",30);
	}
	return 1;
}

int help ()
{
        write(@HELP
指令格式: shutdown
 
重新启动游戏。
 
HELP
);
        return 1;
}
 

