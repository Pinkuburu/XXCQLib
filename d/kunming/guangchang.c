// Room:/d/kunming/guangchang.c
// JackyBoy@CuteRabbits Studio for CCTX 1999/4/17

inherit ROOM;

void create()
{
	set("short", "城中广场");
	set("long", @LONG
这里是昆明城的中心广场，靠边上放着几个石碑，用来公布一些官府的通
告。由于南来北往的行人都从这里经过，所以可以在这里听到不少小道消息，
也可以遇到不少的江湖人士。
LONG
	);
	set("exits", ([
		"south" : __DIR__"nanjie1",
		"west"  : __DIR__"xijie1",
	]));
	set("outdoors","kunming");
	setup();
	replace_program(ROOM);
}
