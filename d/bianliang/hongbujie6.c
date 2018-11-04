// hongbujie6.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "红布街");
	set("long", @LONG
这里是全国闻名的布匹一条街，东边是一座简朴的院子，半月形的大门上方写着
“三友书庄”四个大字，西边是个民宅。

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("outdoors", "bianliang");
	set("exits", ([
		"north" : __DIR__"hongbujie5",
		"south" : __DIR__"hongbujie7",
		"west" : __DIR__"minzhai4",
		"east" : __DIR__"shuzhuang",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "汴梁");
	setup();
	replace_program(ROOM);
}
