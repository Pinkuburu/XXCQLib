// tianshuixiang1.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "甜水巷");
	set("long", @LONG
红布街的西面是贫苦百姓的聚居区，甜水巷比起其他几条街道来也
显得破朽杂乱得多。

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"west" : __DIR__"bh_lukou1",
		"east" : __DIR__"tianshuixiang2",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "汴梁");
	setup();
	replace_program(ROOM);
}
