// Room: shulin2.c
// Created by Zeus 1999.4.8
// Modified by Zeus 1999.4.10
// 修改长描述。
// 

inherit ROOM;
void create ()
{
        set ("short", "树林");
        set ("long", @LONG
这里是一片茂密的树林。向东还是一片树林。向南就是一片
草地了。
LONG);
        set("area","岭南");
        set("outdoors", "wenjia");

        set("exits", ([
                "east" : __DIR__"shulin1",
                "north" : __DIR__"caodi",
        ]));
        setup();
        replace_program(ROOM);
}
