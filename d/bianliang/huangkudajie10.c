// huangkudajie10.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "黄裤大街");
	set("long", @LONG
    这里是黄裤大街的尽头，向东便可到汴梁城的东城门了。远处传来官兵的吆喝
声，不言而知官兵正在那里盘问来来往往的行人。

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("outdoors", "bianliang");
	set("exits", ([
		"north" : __DIR__"budongfeipu",
		"west" : __DIR__"mi_lukou",
		"east" : __DIR__"dongchengmen",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "汴梁");
	setup();
	replace_program(ROOM);
}
