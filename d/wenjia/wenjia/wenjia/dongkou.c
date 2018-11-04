// Room: dongkou.c
// Created by Zeus 1999.4.16
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "洞口");
        set ("long", @LONG
这里有一个大山洞，而你所站的地方是一个大平台。据说这个洞口就
是进入活字号的必经之路。这里守卫着两个温家弟子。
LONG);
        set("area","岭南");
        set("outdoors", "wenjia");
        set("valid_startroom", 1);

        set("exits", ([
                "east" : __DIR__"huoroad8",
                "west" : __DIR__"huikeshi1",
        ]));
        set("objects", ([
               __DIR__"npc/wenjiadizi": 2,
        ]));

        setup();
        replace_program(ROOM);
}
