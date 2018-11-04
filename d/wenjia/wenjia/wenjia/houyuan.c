// Room: houyuan.c
// Created by Zeus 1999.4.8
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "后院");
        set ("long", @LONG
这里是小字号的后院，那里是通往药田的必经之路。一条小路从南到
北的贯穿这一个院子。北面就是小字号种药的药田，而南面是大院。
LONG);
        set("area","岭南");
        set("valid_startroom", 1);

        set("outdoors", "wenjia");

        set("exits", ([
                "south" : __DIR__"dayuan",
                "north" : __DIR__"yaotian1",
        ]));

        setup();
        replace_program(ROOM);
}
