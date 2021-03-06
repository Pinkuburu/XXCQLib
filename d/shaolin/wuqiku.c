// Room: /d/shaolin/wuqiku.c
// Date: YZC 96/01/19

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "武器库");
	set("long", @LONG
少林寺的武器库可称天下第一，十八般兵器，这里可谓应有尽有。四
面一望，令你顿感眼花缭乱。墙上砌了一个个小格子，每个都插满了各种
各样的兵器。墙上贴有一条横幅“与人方便，与己方便”。
LONG );
	set("valid_startroom", 1);

	set("exits", ([
		"west" : __DIR__"zhulin2",
		"north" : __DIR__"fangjuku",
	]));

	set("objects",([
		__DIR__"obj/zhujian" : 1,
		__DIR__"obj/mudao" : 1,
		__DIR__"npc/obj/changjian" : 1,
		__DIR__"npc/obj/chanzhang" : 1,
		__DIR__"npc/obj/jiedao" : 1,
	]));

	setup();

	replace_program(ROOM);
}

