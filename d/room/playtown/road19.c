// /d/playertown/road2.c 碎石小道
// Build 1999.12.10 bmw

inherit ROOM;

void create()
{
	set("short","碎石小道");
	set("long",@LONG
这是一条布满石子的小路，两边长着几颗高大的杨柳树，周围有
一小片空地，景色不错，非常适合建房。
LONG );

	set("recordable_room",1);
	set("outdoors","playertown");
	set("exits",([
		"west" : __DIR__"road18",
		"east" : __DIR__"road20",
	]));
	
	setup();
	
	replace_program(ROOM);
	
}
