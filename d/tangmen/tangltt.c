//tangltt.c		四川唐门—老太太卧室

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "卧室");
	set("long", @LONG
这是唐门掌门唐老太太的卧室。？？？？？？？？？？？？？？？
？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？
谁能描述一下，我没去过。sigh
LONG);
	set("exits", ([
			"south" : __DIR__"nzlang3",
	]));
	set("area", "蜀中");
	set("objects", ([__DIR__"npc/tangltt" : 1,]));
	setup();
	replace_program(ROOM);
}