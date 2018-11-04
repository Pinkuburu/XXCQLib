//wzlang3.c		四川唐门—走廊

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这里是莲云阁西侧的走廊。一到这里立刻变的安静起来，原来这
里通向男女弟子的休息室。不过可不要走错房间呀。
LONG);
	set("exits", ([
			"east" : __DIR__"wzlang2",
			"north" : __DIR__"wselfroom3",
//			"south" : __DIR__"grestroom",
	]));
	set("area", "蜀中");
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if ( (dir == "north") && ( (string)me->query("gender") != "男性") )
		return notify_fail("喂！那里都是男人呀！\n");

	if ( (dir == "south") && ((string)me->query("gender") != "女性") )
		return notify_fail("喂！擅闯女弟子休息室，犯门规的！\n");

	return ::valid_leave(me, dir);
}