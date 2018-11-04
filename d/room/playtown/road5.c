// /d/playertown/road1.c 碎石小道
// Build 1999.12.10 bmw

inherit ROOM;

void create()
{
	set("short","碎石小道");
	set("long",@LONG
这是一条很普通碎石小道，西北面和东北面都是通往村庄的路，
南面是出村的路。
LONG );

	set("recordable_room",1);
	set("outdoors","playertown");
	set("exits",([
		"north" : __DIR__"road6",
		"east" : __DIR__"xuemeiting",
	]));
	
	setup();
	
	replace_program(ROOM);
	
}
