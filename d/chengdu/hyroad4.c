//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "华阳镇西街");
        set ("long", @LONG
这个小镇真的很小，你站的地方在往东就到了小镇的唯一的路口了。
而你的北面是一家打铁铺，叮叮当当的声音伴着股股热浪传来。南面是一
家看来还算体面的宅子。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
            "east" : "/d/longmen/lukou",
		"west" : __DIR__"hyroad3",
//		"south" : __DIR__"hydatie",
       ]));

        set("outdoors", "huayang");
        setup();
}
