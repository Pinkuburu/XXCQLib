// Room: diliufeng.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "第六峰");
        set ("long", @LONG
这里是飞鱼山庄第六峰。四处都是浓浓的白雾，可是风景很不错，但
在这里行走要特别小心，否则会摔下山去的。这里的飞鱼弟子个个都十分
警惕，上下打量着每个人，你觉得浑身不自在，也无心欣赏第六峰的风景
了。顺着西边的山路向下看，你看见了一面飞鱼旗。
LONG);
        set("area","飞鱼");
        set("outdoors", "feiyu");

        set("objects", ([
                __DIR__"npc/feiyudizi" : 2,
        ]));

        set("exits", ([
                "east" : __DIR__"yixiantiannei2",
                "southwest" : __DIR__"shaozhan",
        ]));
        setup();
        replace_program(ROOM);
}

