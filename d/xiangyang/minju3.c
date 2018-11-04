// Room: /city/zahuopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "茅草屋");
	set("long", @LONG
这是一间普通的茅草房，房子家徒四壁，不过布置的非常的干净，看
来这家的女人很爱干净，一个约三十余岁的村妇在扫着地，这个时间男人
应该都出去了。
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"west" : __DIR__"maitian2",
	]));

	set("objects", ([
		__DIR__"npc/cuihua": 1,
	]));

	setup();
	replace_program(ROOM);
}