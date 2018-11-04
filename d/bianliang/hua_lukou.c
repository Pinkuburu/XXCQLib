// hua_lukou.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "路口");
	set("long", @LONG
这里是一个狭长的路口，路上的行人总是行色匆匆的快步经过这条窄
窄的小巷。忽然一阵凉风袭面而来，使人不由得加快自己的脚步。从这里
再往西走，就到了与花府齐名的温宅了。
LONG);	
	set("valid_startroom",1);

        set("outdoors", "bianliang");

	set("exits", ([
                "north" : __DIR__"hongbujie7",
		"east" : __DIR__"huangkudajie4",
		"west" : __DIR__"huangkudajie3",
	]));

	set("area", "汴梁");

	setup();

	replace_program(ROOM);
}
