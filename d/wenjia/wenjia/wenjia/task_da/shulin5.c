// Room: shulin5.c
// Created by Zeus 1999.5.27
// Modified by Zeus 1999.5.27
// 
// 

inherit ROOM;
#include <ansi.h>;

void create ()
{
        set ("short", "树林");
        set ("long", @LONG
茂密的树叶遮挡了阳光，这使你周围环境显得有点阴森。一阵风
吹过，周围的树叶“沙沙”的作响。你发现四周都是大树，不知哪一
路是出路。
LONG);
        set("area","岭南");
        set("valid_startroom", 1);
        set("outdoors", "wenjia");

        set("exits", ([
                "east" : __DIR__"shulin"+(random(8)+1),
                "south" : __DIR__"shulin"+(random(8)+1),
                "west" : __DIR__"shulin"+(random(8)+1),
                "north" : __DIR__"shulin"+(random(8)+1),
                "southeast" : __DIR__"shulin"+(random(8)+1),
                "southwest" : __DIR__"shulin6",
                "northwest" : __DIR__"shulin"+(random(8)+1),
                "northeast" : __DIR__"shulin"+(random(8)+1),
        ]));
        setup();
}
int valid_leave(object me, string dir)
{
        int qi_cost;

        me=this_player();

        qi_cost=(-1) * ( me->query("max_qi") ) / (20 + random(3) );

        if ( dir == "southwest"  && (me->query_temp("taskda/p_given")) ) {
                me->add("qi",qi_cost);
                message_vision(MAG"$N觉得有些眩晕!\n"NOR,me);
        }

        return ::valid_leave(me, dir);
}
