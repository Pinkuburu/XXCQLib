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
风景真是美呀！你忍不住赞叹道。西北边的那座花桥是去桂林镇中心的必
经之路，而西南边是一个港口。
LONG);
        set("area","桂林");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("exits", ([
                "northeast" : __DIR__"jiangdi",
                "southwest" : __DIR__"gangkou",
                "northwest" : __DIR__"huaqiao",
        ]));
        setup();
        replace_program(ROOM);
}

