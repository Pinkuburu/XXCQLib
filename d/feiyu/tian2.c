// Room: tian.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;


void create ()
{
        set ("short", "菜田");
        set ("long", @LONG
这里周围都是一块块的田地，种的都是粮食，看来是飞鱼塘的私田，
大概是因为飞鱼塘在山中吧，万一被人围山时也不会因为粮食不足而被
击败。看来飞鱼山庄真是不简单啊。你正想着，突然发现自己迷路了！
LONG);
        set("area","飞鱼");
        set("valid_startroom", 1);
        set("outdoors", "feiyu");

        set("exits", ([
                "north" : __DIR__"tian3",
                "south" : __DIR__"tian"+(random(4)+1),
                "east" : __DIR__"tian"+(random(4)+1),
                "west" : __DIR__"tian"+(random(4)+1),
        ]));

        setup();
        replace_program(ROOM);
}
