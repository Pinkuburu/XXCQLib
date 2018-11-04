// Room: westsquare.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "西广场");
        set ("long", @LONG
这里与总堂前的广场不同，这里一个人也没有，一阵风吹来你不禁打
了个冷颤。有一种想赶快离开这里的想法。东边已经没有大道了，换而代
之的是一些小路，蜿蜒的通向山上，那是通往死活字号的山路。
LONG);
        set("area","岭南");
        set("outdoors", "wenjia");
        set("valid_startroom", 1);

        set("exits", ([
                "east" : __DIR__"square",
                "west" : __DIR__"shanjing1",
        ]));

        setup();
        replace_program(ROOM);
}
