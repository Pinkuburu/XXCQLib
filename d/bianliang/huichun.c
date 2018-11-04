// Room: /city/huichuntang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "回春堂");
	set("long", @LONG
这是京城最有名的一家药铺，一股浓浓的药味让你几欲窒息，那是从
药柜上的几百个小抽屉里散发出来的。曾经当过御医的上太师坐在茶几旁
，独自喝着茶，看也不看你一眼。一名小伙计站在柜台后招呼着顾客。
LONG
	);

	set("valid_startroom", 1);
	set("objects", ([
		__DIR__"npc/huoji" : 1,
		__DIR__"npc/shang" : 1,
	]));

	set("exits", ([
		"east" : __DIR__"nandajie2",
	]));

	set("area", "汴梁");

	setup();
	replace_program(ROOM);
}

