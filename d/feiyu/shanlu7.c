// Room: shanlu3.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "山路");
        set ("long", @LONG
脚下是一条小土路，路向西面渐渐向上盘旋上山，一直通向落神岭。
向东则连接着青石官道，走那边就可以到秭归镇。
LONG);
        set("area","飞鱼");
        set("outdoors", "feiyu");

        set("exits", ([
                "westup" : __DIR__"shanlu5",
                "east" : "/d/xiangyang/guandao4",
        ]));
        setup();
        replace_program(ROOM);
}