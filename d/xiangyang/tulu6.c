//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "土路");
        set ("long", @LONG
西面就是秭归镇了东口了，不时的有人从镇内出来，延路向东则将穿
过一个小村庄到达长江边的巨石横滩，小村的人想要买一些东西也要从这
条路进镇的。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"west" : __DIR__"zgeast",
		"northeast" : __DIR__"tulu5",
        "north" : "/d/room/playtown/guandao4",
	]));

        set("outdoors", "zigui");
        setup();
}
