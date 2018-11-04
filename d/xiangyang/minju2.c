// Room: /city/zahuopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "茅草屋");
	set("long", @LONG
这是一间普通的茅草房，房子家徒四壁，只有窗户上贴的红窗花才显
出一点生机，土炕上一床茅草，桌子上放着一个小筐。一个老太太叹着气
坐在桌子边上补着衣服。
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"south" : __DIR__"maitian1",
	]));

	set("objects", ([
		__DIR__"npc/laotai": 1,
	]));

	setup();
	replace_program(ROOM);
}