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
脚下是一条小土路，盘旋上山，这条路是一直通向落神岭的。江湖白
道领袖刀柄会六大支柱之一的飞鱼堂据说就在岭的那边。除了飞鱼弟子很
少有人走这条路。
LONG);
        set("area","飞鱼");
        set("outdoors", "feiyu");

        set("exits", ([
                "northup" : __DIR__"shanlu5",
                "eastdown" : __DIR__"shanlu7",
        ]));
        setup();
        replace_program(ROOM);
}