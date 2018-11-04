// Room: huoroad4.c
// Created by Zeus 1999.4.16
// Modified by Zeus 1999.4.16
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "山路");
        set ("long", @LONG
这里是到“活字号”的山路，路旁种的都是一些奇异花草。
说不定这些花草是有毒的？还是快些离开这里吧。向东走是山
路，向南走还是山路。
LONG);
        set("area","岭南");
        set("outdoors", "wenjia");

        set("exits", ([
                "east" : __DIR__"huoroad5",
                "south" : __DIR__"huoroad3",
        ]));
        setup();
        replace_program(ROOM);
}
