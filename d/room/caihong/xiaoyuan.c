// xiaoyuan.c 彩虹居房例之小院
// Written by Doing Lu 1998/1/6

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
	这里是鲁班大师精心搭建的彩虹居的门前小院，院子四周种着一些散发
着淡淡香气的野花，显得生机勃勃。左侧还有一颗大树，枝叶茂盛，使院子益发
显得宁静，只是偶然听见落在树上的鸟儿叽叽喳喳的叫着。
        院子门口有一个小牌子(paizi)， 而北边是一个小门，看来这是通往里
屋的。而回头就是鲁班向弟子们授艺的小院子。
LONG
	);
        set("outdoors", "ground");
//**	set("valid_startroom", 1);

/**/	set("default_long", "这是一间不大院子，四周的墙矮矮的，墙角的一棵大树几乎罩住了" +
/**/			    "半个院子，时常看到鸟儿在这里歇息，棵边的小花淡淡的开着，并" +
/**/			    "不与世间争夺娇艳。\n北面有一扇木门，门边竖着一块牌子(paizi)。");

	set("item_desc", ([
/**/		"paizi"   : "彩虹居 - 鲁班\n",
//**		"paizi"   : "ROOM_NAME - ROOM_OWNER\n",
	]));

	set("key", "ROOM_KEY");
	set("owner", "ROOM_OWNER");

	set("exits", ([
		"out" : "/d/room/xiaoyuan",
		"north" : __DIR__"room1",
	]));

	create_door("north", "厅门", "south", DOOR_CLOSED);

	setup();
}
