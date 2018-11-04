//ekantai1.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "东较武场看台");
	set("long", @LONG
这是唐门的东较武场看台。虽然对于看比武大赛来说，这里不是
最佳的位置，但是这里是喝彩声最响的地方。因为聚在这里的，通常
是唐门的晚辈弟子，最随便，最冲动，也最有激情。南面，是东较武
场的中间看台。
LONG);	
	set("no_steal", "1");
	set("no_fight", "1");
	set("exits", ([
		"south" : __DIR__"ekantai2",
	]));
	setup();
	replace_program(ROOM);
}