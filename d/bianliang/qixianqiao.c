// qixianqiao.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "七贤桥");
	set("long", @LONG
这是国师下令修的七贤桥，富丽堂皇，华丽无比，静悄悄地没有几个行人。

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"qixianjie2",
		"south" : __DIR__"bh_lukou5",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "汴梁");
	setup();
	replace_program(ROOM);
}
