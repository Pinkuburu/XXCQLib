// Room: /welcome/xiting2.c
//By adx @ CuteRabbit 15:57 99-5-18

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",WHT"神雪南廊"NOR);
    set("long", @LONG
你走在一条长长的走廊里，走廊地面铺着青砖，两边的墙上挂着一些字画，
LONG
    );
        set("exits", ([
                "north":__DIR__"nanlang1",
                "south":__DIR__"liangong1",
                "west":__DIR__"yaopu",
                "east":__DIR__"datiepu",
        ]));
        set("no_fight", 1);
	setup();
        replace_program(ROOM);
}
