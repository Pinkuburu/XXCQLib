//changan city

#include <ansi.h>
inherit ROOM;
#include "/kungfu/class/xuehepai/job.h"

void create ()
{
        set ("short", "华阳镇西街");
        set ("long", @LONG
向路南看去，一间木屋外飘着一幅大大的酒幌，一看便知，那是一间
小酒馆。不断有人进出酒馆，有的还提着一壶刚打的酒。路的北面则是一
间伞店，看起来生意不是很好。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"north" : __DIR__"sandian",
		"west" : __DIR__"hyroad3",
		"south" : __DIR__"jiupu",
		"east" : __DIR__"hycs",
        ]));

        set("outdoors", "huayang");
        setup();
}
