// Room: /welcome/donglang1.c
//By adx @ CuteRabbit 15:57 99-5-18

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",WHT"神雪北廊"NOR);
    set("long", @LONG
你走在一条长长的走廊里，走廊地面铺着青砖，两边的墙上挂着一些字画，
LONG
    );
        set("exits", ([
                "south":__DIR__"houting",
                "north":__DIR__"beilang2",
                "west":__DIR__"chaguan",
        ]));
        set("no_fight", 1);
	setup();
        replace_program(ROOM);
}
