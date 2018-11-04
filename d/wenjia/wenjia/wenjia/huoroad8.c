// Room: huoroad8.c
// Created by Zeus 1999.4.16
// Modified by Zeus 1999.6.10
// 
// 

#include <ansi.h>

inherit ROOM;
void create ()
{
        set ("short", "山路");
        set ("long", @LONG
这里是到“活字号”的山路，路旁种的都是一些奇异花草。说不定这
些花草是有毒的？还是快些离开这里吧。向南上去是山路，但是向西走就
不是山路了，而是一个大洞口。
LONG);
        set("area","岭南");
        set("outdoors", "wenjia");
        set("valid_startroom", 1);

        set("exits", ([
                "west" : __DIR__"dongkou",
                "southup" : __DIR__"huoroad7",
        ]));

        setup();
}

void init()
{
        object me = this_player();
	
        if( me->query_skill("dodge",1) < 50) 
        {
                me->receive_damage("qi", 50);
                message_vision(HIR"$N一不小心脚下踏了个空，……啊……！\n"NOR, me);
                me->move(__DIR__"dongkou");
                tell_object(me, HIR"你沿着山路滚了下来，只觉得浑身无处不疼，还受了几处伤。\n"NOR);
                message("vision", HIR"只见" + me->query("name") + "从山上骨碌碌地滚了下来，躺在地上半天爬不起来！\n"NOR, environment(me), me);
        }
}
