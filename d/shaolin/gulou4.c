// Room: /d/shaolin/gulou4.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "鼓楼四层");
	set("long", @LONG
到这里楼梯大概只能容一人上下，墙身也略薄了些。视线越过窗棂，
南边的练武场，罗汉堂，般若堂历历在目，不少僧人正汇集在练武场上习
武，吆喝声一阵阵传进耳鼓。北边的藏经楼，方丈楼也尽露全貌。
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"up" : __DIR__"gulou5",
		"down" : __DIR__"gulou3",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

