// Room: bingqifang.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "兵器房");
        set ("long", @LONG
兵器房里什么兵器都有，兵器架整齐的排列着，可能有专人整理的吧。
温家弟子没有固定的兵器，所以温家弟子可以在这里找到适合自己的兵器。
西边的门通往药房，向南走就是东练武场。
LONG);
        set("area","岭南");
        set("valid_startroom", 1);

        set("exits", ([
                "east" : __DIR__"yaofang",
                "south" : __DIR__"donglianwuchang",
        ]));

        set("objects", ([
                "/clone/weapon/changjian" : 1,
                "/clone/weapon/dandao" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
