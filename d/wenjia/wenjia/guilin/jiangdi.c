// Room: jiangdi.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "江堤");
        set ("long", @LONG
一条长长的堤岸，旁边的漓江江水缓缓的流着，周围种植着好些桂树，
风景真是美呀！你忍不住赞叹道。总不能留在这里不走呀，东南边一眼望
去是一片桂树林，而西南边在江上有一座桥，叫做“花桥”，那里是去镇
中心的必经之路。
LONG);
        set("area","桂林");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("exits", ([
                "northeast" : __DIR__"lingqu",
                "southeast" : __DIR__"guishulin1",
                "southwest" : __DIR__"jiangdi1",
        ]));
        setup();
        replace_program(ROOM);
}

