//nzlang3.c		四川唐门—走廊

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
			"south" : __DIR__"nzlang2",
			"north" : __DIR__"tangltt",
			"west" : __DIR__"tangshe",
			"east" : __DIR__"tangting",
	]));
	set("area", "蜀中");
	setup();
	replace_program(ROOM);
}