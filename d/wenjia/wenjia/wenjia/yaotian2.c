// Room: yaotian2.c
// Created by Zeus 1999.4.9
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "药田");
        set ("long", @LONG
这里周围都是一块块的田地，很奇怪这里种的不是粮食，而是一些样
子非常奇怪的植物。这里很明显种的是温家小字号所制造毒药的原料。很
显然你在这齐人高的田地里迷路了。
LONG);
        set("area","岭南");
        set("valid_startroom", 1);
        set("outdoors", "wenjia");

        set("exits", ([
                "north" : __DIR__"yaotian3",
                "south" : __DIR__"yaotian"+(random(6)+1),
                "east" : __DIR__"yaotian"+(random(6)+1),
                "west" : __DIR__"yaotian"+(random(6)+1),
        ]));

        setup();
        replace_program(ROOM);
}
