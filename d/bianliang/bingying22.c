// bingying2.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "驻军兵营");
	set("long", @LONG
这是一间按行军帐篷布置的营房，长案居中，红毯铺地，一名身披金
丝甲的将军正大声的呵斥着一名武官，其他几名武官则颤栗的站在两旁，
大气都不敢喘一下。你一进来都就有一种要大祸临头的感觉。
LONG);	
	set("valid_startroom",1);

	set("exits", ([
		"west" : __DIR__"bingying2",
	]));

	set("objects", ([
		__DIR__"npc/xianyuchou" : 1,
	]));

	set("area", "汴梁");

	setup();

	replace_program(ROOM);
}