// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "振眉阁");
	set("long", @LONG
振眉阁内没有点灯，黑漆漆的，你只能模糊的环视，看到四周的摆设
非常的简单，突然你看到黑暗中有两个老妇人，一个坐在椅子上，闭目养
神，另一个站在她的身边，你和她的目光刹那的对视，突然心中一冷，连
忙将目光移开了。
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"south" : __DIR__"luohua",
	]));

	setup();
	replace_program(ROOM);
}
