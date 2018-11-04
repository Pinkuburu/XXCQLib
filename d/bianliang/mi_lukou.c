// mi_lukou.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "路口");
	set("long", @LONG
    这里是一个开阔的路口，路上的行人总是神色紧张的快步经过这条宽
阔的小巷。忽然一阵凉风袭面而来，使人不由得加快自己的脚步。从这里
再往北走，就到了破板门了。

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("sleep_room",1);
	set("exits", ([
		"north" : __DIR__"pobanmen5",
		"east" : __DIR__"huangkudajie10",
		"west" : __DIR__"huangkudajie9",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "汴梁");
	setup();
	replace_program(ROOM);
}
