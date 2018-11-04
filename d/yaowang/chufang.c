// Room: 药王谷
// By 山猫adx @ 宁波小雪 17:00 99-10-26

inherit ROOM;

void create()
{
	set("short", "厨房");
	set("long", @LONG
这里就是药王谷的厨房，一整排的炉灶，大大的铁锅，一看就知道这
里要提供全谷弟子的饮食。你如果饿了，可以向厨子要些吃的。
LONG );
	set("area", "药王谷");
	set("areb", "厨房");
	set("no_fight", 1);
	set("exits", ([
		"south" : __DIR__"dongting",
	]));

	set("objects", ([
		__DIR__"npc/huoji3" : 1,
	]));
	setup();
	replace_program(ROOM);
}
