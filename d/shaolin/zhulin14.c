// Room: /city/milin.c

inherit ROOM;

void create()
{
	set("short", "青竹林");
	set("long", @LONG
这是一片茂密的青竹林，密密匝匝已经没有路了，只见周围翠竹株株
如刺天之剑，根本看不到尽头，一走进来，你仿佛迷失了方向。听说这片
竹林是通向面壁石的必经之路。
LONG );
	set("exits", ([
		"east" : __DIR__"zhulin11",
		"west" : __FILE__,
		"south" : __DIR__"zhulin15",
		"north" : __FILE__,
	]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}
