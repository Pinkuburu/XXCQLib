// pobanmen3.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "破板门");
	set("long", @LONG
这里的街面要比别处的干净、整洁。静悄悄地没有几个行人，西边是个文府。

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"pobanmen2",
		"south" : __DIR__"pobanmen4",
		"west" : __DIR__"wwenfu",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "汴梁");
	setup();
	replace_program(ROOM);
}
