// Room: /city/zahuopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "茅草屋");
	set("long", @LONG
这是一间普通的茅草房，房子家徒四壁，只有一张桌子和两把破凳子
，土炕上一床茅草，桌子上放着一小碟咸菜。一个老汉叹着气坐在桌子边
上发呆。
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"west" : __DIR__"tulu1",
	]));

	set("objects", ([
		__DIR__"npc/laohan": 1,
	]));

	setup();
	replace_program(ROOM);
}