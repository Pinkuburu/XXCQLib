//changan city

#include <ansi.h>
inherit ROOM;
#include "/kungfu/class/xuehepai/job.h"

void create ()
{
        set ("short", "镇中心");
        set ("long", @LONG
站在镇中心，东南西北你一眼可以看穿整个华阳小镇，南北两条小巷
主要都是民居，向东不远就出镇了，西面则是几家小店，几个孩童在这里
玩耍，不时的还有马车经过。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"north" : __DIR__"xiaox1",
		"west" : __DIR__"hyroad4",
		"south" : __DIR__"xiaox2",
		"east" : __DIR__"hyroad6",
        ]));

        set("outdoors", "huayang");
        setup();
}
