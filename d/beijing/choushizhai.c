// 出自《温柔一刀》
// Room: /city/choushiju.c
// LOAD 1999/1/29 

inherit ROOM;

void create()
{
	set("short", "愁石斋");
	set("long", @LONG
	这里本是一个很平常的小店，经营一些小字画，但由于这里是现今象鼻塔
的领头人王小石曾经的隐居之所，更因为王小石在这里一人破八大刀王联手，所以
这里已是无人不知，无人不晓。这里的摆设非常素雅，一把红椅，一张长几摆有文
房四宝，再有的就是墙上的各幅字画了。
LONG
	);

	set("valid_startroom", 1);
        set("no_sleep_room",1);
	set("no_fight",1);
	set("no_beg",1);

	set("objects", ([
	]));

	set("exits", ([
		"south" : __DIR__"shalan-w2",
	]));

}

