// Room: /city/zahuopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "茅草屋");
	set("long", @LONG
这是一间普通的茅草房，房子家徒四壁，看来非常的脏乱，看起来家
里只有一个男人，一个二十余岁的汉子在屋里叮叮当当的敲打着，好像在
做家具。
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"south" : __DIR__"tulu8",
	]));

	set("objects", ([
		__DIR__"npc/awang": 1,
	]));

	setup();
	replace_program(ROOM);
}