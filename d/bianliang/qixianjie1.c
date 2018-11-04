// qixianjie1.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "七贤街");
	set("long", @LONG
这是一条宽阔的青石板街道，向南北两头延伸。往西是就国师府，往东是祢御史府。

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"by_lukou",
		"south" : __DIR__"qixianjie2",
		"west" : __DIR__"by_guoshifu",
		"east" : __DIR__"by_yushifu",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "汴梁");
	setup();
	replace_program(ROOM);
}
