//houroad4.c		四川唐门—青石小路

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "青石小路");
	set("long", @LONG
这里是后宅西侧的青石小路。隐隐的可以听到远处传来清脆的流
水声，展目望去已经可以看见在风中摇摆的片片荷叶。一阵清风吹过
带来一股荷花清香。
LONG);
	set("exits", ([
			"west" : __DIR__"houyuan",
			"east" : __DIR__"houroad3",
			"northwest" : __DIR__"dufang",
			"southwest" : __DIR__"dcailiao",
	]));
	set("area", "蜀中");
	setup();
	replace_program(ROOM);
}