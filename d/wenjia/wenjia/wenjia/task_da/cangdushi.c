// Room: cangdushi.c
// Created by Zeus 1999.5.12
// Modified by Zeus 1999.5.12
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "藏毒室");
        set ("long", @LONG
这里是老字号温家中大字号的藏毒室，这里藏的毒都是一些非
常常见的毒药，至于重要的毒药吗…………
LONG);
        set("area","岭南");

        set("exits", ([
                "north" : __DIR__"duku",
                "out" : "/d/wenjia/xiaojing",
        ]));

        set("objects", ([
                __DIR__"npc/wenxiao" : 1,
        ]));

        replace_program(ROOM);
        setup();
}