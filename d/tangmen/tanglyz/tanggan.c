//tanggan.c		四川唐门—唐感卧室

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "寝室");
	set("long", @LONG
这是一间简陋的卧室。屋中只有一张硬木床和一张枣木红桌。
这里住着唐老太太的贴身保镖唐感。
LONG);
	set("exits", ([
			"west" : __DIR__"nzlang2",
	]));
	set("area", "蜀中");
	set("objects", ([__DIR__"npc/tanggan" : 1,]));
	setup();
	replace_program(ROOM);
}