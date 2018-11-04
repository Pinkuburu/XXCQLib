// void.c (re-created after Elon screwed it up on 07-24-95)

inherit ROOM;

int sid;

void create()
{
	set("short","我杀");
	set("long",@LONG	
我杀杀杀！
LONG
	);
	setup();
}

void init()
{
	add_action("do_test","t");
}

int do_test(string arg)
{
	"/adm/daemons/socketd"->add_session("我杀！",this_object());
	write("/adm/daemons/socketd"->show_session());
	return notify_fail("命令已经发送\n");
}

int incoming(string sid,string msg)
{
	CHANNEL_D->do_channel(this_object(),"chat","收到编号为"+sid+"的信息返回："+msg);
	tell_room(this_object(),"hi!"+sid);//未执行
	return 1;
}
