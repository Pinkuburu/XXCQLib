// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit YIZHAN;

void create()
{
	set("short", "华阳驿站");
	set("long", @LONG
这是一间大屋子隔出来的一个小屋子，你的面前是一个破旧的木制柜
台，柜台上对有一些本子，却没有人，柜台侧面有一个大门，门虚掩着，
里面传来马的嘶鸣声，如果你想坐车，就雇一辆(gu che)吧。
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"south" : __DIR__"hyroad2",
	]));

	setup();
}