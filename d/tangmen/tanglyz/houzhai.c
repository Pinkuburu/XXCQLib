//houzhai.c		四川唐门—走廊

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "后宅");
	set("long", @LONG
这里是莲云阁后宅。从这里向北就是唐门的龙头唐老太太的寝室
据闻外人要见到唐老太太势比登天还难，从这里向东是一间柴房，向
西是通向后院的小路。
LONG);
	set("exits", ([
			"north" : __DIR__"nzlang2",
	]));
	set("objects", ([__DIR__"npc/tangsi" : 1,]));
	set("area", "蜀中");
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if ( (dir == "north") && ( (string)me->query("family/family_name") != "四川唐门") && !wizardp(me) && (objectp( present("tang si", environment(me)) ) ))
		return notify_fail("唐思一伸手，说道：“你不是唐门中人，不能再向前走了！”\n");
	else
		return ::valid_leave(me, dir);
}