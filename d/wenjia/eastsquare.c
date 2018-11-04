// Room: eastsquare.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.4.10
// 修改长描述。
// 

inherit ROOM;
void create ()
{
        set ("short", "东广场");
        set ("long", @LONG
这里与总堂前的广场不同，这里一个人也没有，一阵风吹来
你不禁打了个冷颤。有一种想赶快离开这里的想法。西边已经没
有大道了，换而代之的是一些小路，蜿蜒的通向山上，那是通往
死活字号的山路。
LONG);
        set("area","岭南");
        set("outdoors", "wenjia");

        set("exits", ([
                "eastdown" : __DIR__"huoroad1",
                "west" : __DIR__"square",
                "northeast" : __DIR__"siroad1",
        ]));
        setup();
        replace_program(ROOM);
}
