// room3.c 彩虹居房例之房间3
// Written by Doing Lu 1998/1/6

// 在生成房屋时：
// /**/开头的语句将被去掉
// //**开头的语句将被使用。

#include <room.h>
/**/inherit ROOM;
//**inherit PRIVATE_ROOM;

void create()
{
	set("short", "侧室");
	set("long", @LONG
	这里是鲁班大师精心搭建的彩虹居的侧室，屋子里不是很大，现在还是
空空的，什么也没有。
LONG
	);

	set("no_fight", 1);
//**	set("sleep_room", 1);

/**/	set("default_long", "这里就是侧室，是来访客人常住的地方，屋角有一张床。");
	set("key", "ROOM_KEY");
	set("owner", "ROOM_OWNER");

	set("exits", ([
		"west" : __DIR__"room1",
	]));

	setup();
}
