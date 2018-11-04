// huangkudajie9.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "黄裤大街");
	set("long", @LONG
        大街从这里往西突然开阔起来，路边开始出现一些店铺之类的房屋，
由于车辆，行人繁多，这里的店铺生意也比别处红火，往南则是著名的迷天盟了。

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("outdoors", "bianliang");
	set("exits", ([
		"south" : __DIR__"mitianmengmen",
		"west" : __DIR__"huangkudajie8",
		"east" : __DIR__"mi_lukou",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "汴梁");
	setup();
	replace_program(ROOM);
}
