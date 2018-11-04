// /d/playertown/road1.c 碎石小道
// Build 1999.12.10 bmw

inherit ROOM;

void create()
{
	set("short","青砖路");
	set("long",@LONG
这是一条非常平整的青砖铺成的路，北面是一个非常别致的小花
园，东面是村女们经常光顾的地方 -清心池，东南面是一个三岔
口，是出村的必经之路。
LONG );

	set("recordable_room",1);
	set("outdoors","playertown");
	set("no_clean_up",0);
	
	set("exits",([
		"north"	:	__DIR__"huayuan4",
		"east"	:	__DIR__"nvyutang",
		"southwest"	:	__DIR__"road8",
	]));
	
	setup();
	
	replace_program(ROOM);
	
}
