// huangkudajie5.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "黄裤大街");
	set("long", @LONG
大街从这里往西突然开阔起来，路边已经没有各种店铺、民房了，往
西边望去，看到不远就是京城最大的广场了。西边则通向京城有名的帮派
花府和温府。
LONG);	
	set("valid_startroom",1);

	set("exits", ([
                "west" : __DIR__"huangkudajie4",
		"east" : __DIR__"guangchang",
//              "west" : __DIR__"jiebei3",
	]));

	set("outdoors", "bianliang");
	set("area", "汴梁");

	setup();

	replace_program(ROOM);
}
