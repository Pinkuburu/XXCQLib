// hongbujie3.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "红布街");
	set("long", @LONG
这里是红布街的尽头,向东便可到烟花巷去，每天都有不少人进出。

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("outdoors", "bianliang");
	set("exits", ([
		"north" : __DIR__"bh_lukou2",
		"south" : __DIR__"hongbujie4",
		"east" : __DIR__"yanhuaxiang",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "汴梁");
	setup();
	replace_program(ROOM);
}
