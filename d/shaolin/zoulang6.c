// Room: /d/shaolin/zoulang6.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这里是禅房走廊。走廊南侧的房顶倚着南面的高墙，另一侧则与北边
和尚院的屋顶相连。南面墙上挂了一付对联：“悟彻菩提真妙理，断魔归
本合元神”。
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"west" : __DIR__"zoulang5",
		"east" : __DIR__"fzlou",
		"south" : __DIR__"wuchang1",
		"north" : __DIR__"chanfang1",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

