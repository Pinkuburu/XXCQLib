// Room: huoroad6.c
// Created by Zeus 1999.4.16
// Modified by Zeus 1999.4.16
// 
// 
#include <ansi.h>

inherit ROOM;
void create ()
{
        set ("short", "山路");
        set ("long", @LONG
这里是到“活字号”的山路，路旁种的都是一些奇异花草。
说不定这些花草是有毒的？还是快些离开这里吧。向西走是山
路，向北上去还是山路。
LONG);
        set("area","岭南");
        set("outdoors", "wenjia");

        set("exits", ([
                "west" : __DIR__"huoroad7",
                "northup" : __DIR__"huoroad5",
        ]));
        setup();
}

void init()
{
        object me = this_player();
	
        if( (int)me->query_skill("dodge",1) < 50) 
        {
                me->receive_damage("qi", 100);
                me->receive_wound("qi",  100);
                message_vision(HIR"$N一不小心脚下踏了个空，……啊……！\n"NOR, me);
                me->move(__DIR__"dongkou");
                tell_object(me, HIR"你沿着山路滚了下来，只觉得浑身无处不疼，还受了几处伤。\n"NOR);
                message("vision", HIR"只见" + me->query("name") + "从山上骨碌碌地滚了下来，躺在地上半天爬不起来！\n"NOR, environment(me), me);
        }
}
