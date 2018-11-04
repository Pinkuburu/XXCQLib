// bh_lukou3.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "路口");
	set("long", @LONG
这是个十字路口，地面上铺着青石，经常有艺人在这里表演,这里四通八达。

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"gongqiao",
		"south" : __DIR__"huangshanjie1",
		"west" : __DIR__"quyuanjie2",
		"east" : __DIR__"banyejie1",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "汴梁");
	setup();
	replace_program(ROOM);
}
