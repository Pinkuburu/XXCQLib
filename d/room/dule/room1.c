// room1.c 独乐居房例之房间1
// Written by Doing Lu 1998/12/30

// 在生成房屋时：
// /**/开头的语句将被去掉
// //**开头的语句将被使用。

#include <room.h>
/**/inherit ROOM;
//**inherit PRIVATE_ROOM;

void create()
{
	set("short", "小屋");
	set("long", @LONG
	这里是鲁班大师精心搭建的独乐居的小屋，从精致花木格窗户还依稀可
以看到院子的景观，屋子里有一个桃木桌，在屋角有一个床，上面打扫的一尘不
染，屋子虽小，却让人感觉到温馨倍至。
LONG
	);

	set("no_fight", 1);
//**	set("sleep_room", 1);

/**/	set("default_long", "这是一间不大的屋子，透过精致的花木格窗户依稀可以看到院子的景观。屋角房着一张床，看上去非常舒适。");

	set("key", "ROOM_KEY");
	set("owner", "ROOM_OWNER");

	set("exits", ([
		"south" : __DIR__"xiaoyuan",
	]));

	create_door("south", "木门", "north", DOOR_CLOSED);

	setup();
}
