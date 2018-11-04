// Room: shanlu1.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "山路");
        set ("long", @LONG
青石路在这里已经看不见了，脚下变成了泥土路，从这里再向东上去
就是飞鱼山庄总堂了。这里可以看见一些飞鱼弟子在这里把守着，他们的
神情都很紧张，可能是最近闯上来的外人多了吧。看来不宜久留。向北看
去，是一大片菜地。
LONG);
        set("area","飞鱼");
        set("outdoors", "feiyu");

        set("objects", ([
                __DIR__"npc/feiyudizi" : 2,
        ]));

        set("exits", ([
                "southeast" : __DIR__"yixiantian",
                "eastup" : __DIR__"lysquare",
                "north" :__DIR__"tian5",     
        ]));
        setup();
        replace_program(ROOM);
}
