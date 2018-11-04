// bingying1.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "驻军兵营");
	set("long", @LONG
这是一间按行军帐篷布置的营房，长案居中，红毯铺地，走进这里你
感到一股深深的压力，一名红披风、黑甲的将军坐在案后，六名武官分列
两旁，见到你进来都侧目看着你，但那位将军却头也不抬，继续读着手中
的案卷。
LONG);	
	set("valid_startroom",1);

	set("exits", ([
		"east" : __DIR__"bingying1",
	]));

	set("objects", ([
		__DIR__"npc/lenghuer" : 1,
	]));

	set("area", "汴梁");

	setup();

	replace_program(ROOM);
}