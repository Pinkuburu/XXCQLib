// wazixiang1.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "瓦子巷");
	set("long", @LONG
这里是汴梁城的瓦子巷,不过是一条小胡同而已。路上一个人也没有。

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"bh_lukou1",
		"south" : __DIR__"wazixiang2",
		"west" : __DIR__"jinshifang",
		"east" : __DIR__"choushizhai",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "汴梁");
	setup();
	replace_program(ROOM);
}
