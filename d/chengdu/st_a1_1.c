// Room:/d/chengdu/st_a1_1.c
// JackyBoy@CuteRabbits Studio for CCTX 1999/9/13

inherit ROOM;

void create()
{
	set("short", "丁字路口");
	set("long", @LONG
这是一个丁字路口的客栈，往东就是成都有名的小吃街了，远远看去人声嘈杂
很是热闹。南方有一座道观
LONG
	);

	set("no_fight", 1);
	set("valid_startroom", 1);
	set("no_sleep_room",1);

	set("exits", ([

	]));

	setup();
	replace_program(ROOM);
}
