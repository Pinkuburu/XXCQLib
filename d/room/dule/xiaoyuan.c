// xiaoyuan.c 独乐居房例之小院
// Written by Doing Lu 1998/12/30

// 在生成房屋时：
// /**/开头的语句将被去掉
// //**开头的语句将被使用。

#include <room.h>
/**/inherit ROOM;
//**inherit PRIVATE_ROOM;

void create()
{
	set("short", "小院");
	set("long", @LONG
	这里是鲁班大师精心搭建的独乐居的门前小院，院子四周种着一些散发
着淡淡香气的野花，显得生机勃勃。虽然院子不大，却给人以一种安静宁溢的感
觉，使人有说不出的畅意，真想吟诗一首，以和佳境。
        院子门口有一个小牌子(paizi)， 而北边是一个小门，看来这是通往里
屋的。而回头就是鲁班向弟子们授艺的小院子。
LONG
	);
        set("outdoors", "ground");
//**	set("valid_startroom", 1);

/**/	set("default_long", "这是一间小小的院子，种满了不知名的小花，散发着淡淡的香气。\n北面有一扇木门，门边竖着一块牌子(paizi)。");

	set("item_desc", ([
/**/		"paizi"   : "独乐居 - 鲁班\n",
//**		"paizi"   : "ROOM_NAME - ROOM_OWNER\n",
	]));

	set("key", "ROOM_KEY");
	set("owner", "ROOM_OWNER");

	set("exits", ([
		"out" : "/d/room/xiaoyuan",
		"north" : __DIR__"room1",
	]));

	create_door("north", "木门", "south", DOOR_CLOSED);

	setup();
}
