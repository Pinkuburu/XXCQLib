// yanhuaxiang.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "烟花巷");
	set("long", @LONG
这里是小巷，每天都有不少人进出，北面是曲院街。

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"quyuanjie1",
		"west" : __DIR__"hongbujie3",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "汴梁");
	setup();
	replace_program(ROOM);
}
