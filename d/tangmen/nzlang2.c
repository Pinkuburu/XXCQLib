//nzlang2.c		四川唐门—走廊

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这里是莲云阁北侧的走廊。两旁是碧绿的湖水，无数荷花含苞欲
放，这美景让人留连忘返，止步不前。这里通向莲云阁后宅。
LONG);
	set("exits", ([
			"south" : __DIR__"houzhai",
			"north" : __DIR__"nzlang3",
			"west" : __DIR__"tangwen",
			"east" : __DIR__"tanggan",
	]));
	set("area", "蜀中");
	setup();
	replace_program(ROOM);
}