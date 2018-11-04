// caishikou.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "菜市口");
	set("long", @LONG
一到这里，你就觉得阴风阵阵，四周看去，行人极少，与汴梁的繁华完
全不同。这里就是著名的菜市口了。唯一能使这里热闹的日子，只有在处斩
犯人的时候才能出现。一座木台子搭在南面，上面隐隐有着血迹。
LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"heibujie7",
		"west" : __DIR__"huangkudajie7",
		"east" : __DIR__"huangkudajie8",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "汴梁");
	setup();
	replace_program(ROOM);
}
