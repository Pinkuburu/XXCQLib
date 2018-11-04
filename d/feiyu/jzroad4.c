// Room: jzroad4.c


inherit ROOM;

void create()
{
        set("short", "峭壁");
        set("long", @LONG
你走在峭壁边的小路上。一侧是密密的丛林，外侧却是极深的陡壁。
山风凛冽，几乎要把你刮落崖去。
LONG );
        set("exits", ([ 
            "westdown" : __DIR__"jzroad3",
            "northup"  : __DIR__"houshan",
        ]));
        set("outdoors", "feiyu");

		setup();
        replace_program(ROOM);
}

