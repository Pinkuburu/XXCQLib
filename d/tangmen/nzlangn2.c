//nzlangn2.c		四川唐门—青石小路

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "青石小路");
	set("long", @LONG
这是一条青石铺就的小路。由于来来往往的人数太多，粗糙的青
石已经被磨的光滑如镜。一些唐门的弟子往来穿梭，这里还真是很热
闹。这里向
LONG);
	set("exits", ([
			"south" : __DIR__"nzlangn1",
			"north" : __DIR__"nzlangn3",
	]));
	set("area", "蜀中");
//	set("objects", ([__DIR__"npc/tangfang" : 1,]));
	setup();
	replace_program(ROOM);
}