// bh_lukou2.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "路口");
	set("long", @LONG
这里是个丁字路口，北边是一条青石大道，人来人往。

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"south" : __DIR__"hongbujie3",
		"west" : __DIR__"tianshuixiang2",
		"east" : __DIR__"quyuanjie1",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "汴梁");
	setup();
	replace_program(ROOM);
}
