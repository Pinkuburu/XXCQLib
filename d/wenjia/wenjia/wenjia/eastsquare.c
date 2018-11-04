// Room: eastsquare.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "东广场");
        set ("long", @LONG
这里与总堂前的广场不同，这里一个人也没有，一阵风吹来你不禁打
了个冷颤。有一种想赶快离开这里的想法。西边已经没有大道了，换而代
之的是一些小路，蜿蜒的通向山上，那是通往死活字号的山路。在路边竖
了一块木牌(mupai)。
LONG);
        set("area","岭南");
        set("outdoors", "wenjia");
        set("valid_startroom", 1);

        set("item_desc", ([
                 "mupai" : "东北方：死字号\n东  面：活字号\n山路崎岖，请轻功不佳者勿去。\n                    温瑞安\n",
        ]));

        set("exits", ([
                "eastdown" : __DIR__"huoroad1",
                "west" : __DIR__"square",
                "northeast" : __DIR__"siroad1",
        ]));

        setup();
        replace_program(ROOM);
}
