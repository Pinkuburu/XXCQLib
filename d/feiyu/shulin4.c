// Room: shulin1.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
#include <ansi.h>
#include <room.h>

void create ()
{
        set ("short", "树林");
        set ("long", @LONG
茂密的树叶遮挡了阳光，这使你周围环境显得有点阴森。一阵风吹过
，周围的树叶“沙沙”的作响。你发现四周都是大树，不知哪一边是出路
。你好象已经迷路了。你有些害怕，突然林中跳出一只不知名的动物，吓
了你一大跳。
LONG);
        set("area","飞鱼");
        set("valid_startroom", 1);
        set("outdoors", "feiyu");

        set("exits", ([
                "east" : __DIR__"shulin"+(random(4)+1),
                "south" : __DIR__"huangdi",
                "west" : __DIR__"shulin"+(random(4)+1),
                "north" : __DIR__"shulin"+(random(4)+1),
                
        ]));
        setup();
}

