// Room:/d/kunming/xijie1.c
// JackyBoy@CuteRabbits Studio for CCTX 1999/4/17

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
往东是昆明的城中广场，南边的客栈上挂着一幅小旗(qi)，龙飞凤舞地写
着几个大字，继续往西则是昆明出名的手工制品街。北边却是官府的监狱
大牢，听说经常关有一些重刑犯。
LONG
	);
	set("exits", ([
		"south" : __DIR__"kedian",
		"east": __DIR__"guangchang",
		"north": "/d/sroom/jianyu_men",
	]));
	set("outdoors","kunming");
	setup();
	replace_program(ROOM);
}
