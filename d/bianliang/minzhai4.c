// minzhai4.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "民宅");
      set("long", @LONG
这户人家在汴梁城里也算富裕了,屋里供着南海观音和关王爷的神像。

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"east" : __DIR__"hongbujie6",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "汴梁");
	setup();
	replace_program(ROOM);
}
