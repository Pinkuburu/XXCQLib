// pobanmen1.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "破板门");
	set("long", @LONG
这里的街面要比别处的干净、整洁。静悄悄地没有几个行人。

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"bh_lukou5",
		"south" : __DIR__"pobanmen2",
//		"west" : __DIR__"xb_helianwangfu",
//		"east" : __DIR__"xb_tongguanfu",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "汴梁");
	setup();
	replace_program(ROOM);
}
