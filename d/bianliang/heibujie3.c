// heibujie3.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "黑布街");
	set("long", @LONG
你走在一条尘土飞扬的大道上。四周人来人往。挑担子的商
人，赶着大车的马夫，熙熙攘攘，非常热闹。不时还有两三骑快
马从身边飞驰而过，扬起一路尘埃。

LONG);	
//	set("valid_startroom",1);
//	set("no_steal", "1");
//	set("no_fight", "1");
//	set("outdoors", "bianliang");
	set("exits", ([
		"north" : __DIR__"bh_lukou4",
		"south" : __DIR__"heibujie4",
//		"west" : __DIR__"xb_helianwangfu",
//		"east" : __DIR__"xb_tongguanfu",
	]));
//	set("objects", ([
//		"/clone/weapon/changjian" : 4]));
	set("area", "汴梁");
	setup();
	replace_program(ROOM);
}
