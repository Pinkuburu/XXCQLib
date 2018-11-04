// Room: 汴梁药局
// By 山猫adx @ 宁波小雪 17:00 99-10-26

inherit ROOM;

void create()
{
	set("short", "南厅");
	set("long", @LONG
这是一间大大的房间，放着整排药柜，一股浓浓的药味让你
几欲窒息，那是从药柜上的几百个小抽屉里散发出来的。
LONG );
	set("area", "汴梁东");
	set("areb", "回春堂");
	set("no_fight", 1);
	set("exits", ([
		"north" : __DIR__"tingyuan",
		"west" : __DIR__"neiwu",
	]));
	set("objects", ([
		__DIR__"npc/huoji1" : 1,
	]));
	setup();
	replace_program(ROOM);
}
