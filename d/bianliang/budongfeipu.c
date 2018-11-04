// budongfeipu.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "不动飞瀑");
	set("long", @LONG
转过一个小道，听见水声震耳欲聋，只见一条大白龙似的瀑布奔泻而
下，水花飞溅，四顾水气蒙蒙，蔚为奇观。那山洪势道猛烈，令人颇有惧
意，还是别乱来的好。

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"south" : __DIR__"huangkudajie10",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "汴梁");
	setup();
	replace_program(ROOM);
}
