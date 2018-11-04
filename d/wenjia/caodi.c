// Room: caodi.c
// Created by Zeus 1999.4.8
// Modified by Zeus 1999.4.10
// 修改长描述。
// 

inherit ROOM;
void create ()
{
        set ("short", "草地");
        set ("long", @LONG
这里是小字号建筑群前面的一片草地。草长得十分得矮，绿
油油的十分好看。向南走是小字号的会客室，向北走就回到了那
片树林。
LONG);
        set("area","岭南");
        set("outdoors", "wenjia");

        set("exits", ([
                "south" : __DIR__"shulin2",
                "north" : __DIR__"huikeshi",
        ]));
        setup();
        replace_program(ROOM);
}
