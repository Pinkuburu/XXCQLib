// tieqipu.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "铁器铺");
	set("long", @LONG
这里是一间打铁铺子，从火炉中冒出的火光将墙壁映得通红，屋子的
角落里堆满了象斧子、铁锤、长剑等各式铁器，叮叮当当的声音敲得
满屋子响。
LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"huangkudajie7",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "汴梁");
	setup();
	replace_program(ROOM);
}
