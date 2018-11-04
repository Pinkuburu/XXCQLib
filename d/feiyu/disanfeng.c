// Room: disanfeng.c
// Created by Atlus 1999.10.10
// Modified by Atlus 1999.10.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "第三峰");
        set ("long", @LONG
这里是飞鱼第三峰。四处都是浓浓的白雾，可是风景很不错，但在这
里行走要特别小心，否则会摔下山去的。两边的悬崖使你觉得浑身不自在
，雾中可以隐约见到一条下山的路。
LONG);
        set("area","feiyu");
        set("outdoors", "feiyu");

        set("exits", ([
                "southdown" : __DIR__"houshan",
        ]));
        setup();
       
}

void init()
{
        object me = this_player();
        if (me->query_temp("feiyutask/given")) me->set_temp("di3mark", 1);
        return;
}
