// Room: xiaowu.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create()
{
        set("short", "铁匠房");
        set("long", @LONG
这里是飞鱼塘里的铁匠房，制造各种武器．一进门，只觉得热气袭面
而来,使人透不过气来，眼前是一排铁炉,只见几个铁匠正在卖力地干活．
还有一个带工的在不断巡视．
LONG);
        set("area","飞鱼");
        set("valid_startroom", 1);

        set("exits", ([
                "north" : __DIR__"zhailu",
        ]));

        set("objects", ([
                       __DIR__"npc/tiejiang" : 1,
                       __DIR__"obj/tielu" : 1,
        ]));

		setup();
}

