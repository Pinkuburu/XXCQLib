// 山猫ADX by snow 99-12-4

#include <ansi.h>
inherit ROOM;

void create ()
{
	set("short",  "神雪山腰");
	set("long",  @LONG
你爬上山腰，面前有一座高大的山门，新手一般要在这里学习在江湖
中的基本生存技能。
LONG);
	set("exits",  ([
		"west"  :  __DIR__"menqian",
		"eastdown"  :  __DIR__"shanjiao",
	]));
	set("outdoors",  1);
	setup();
	replace_program(ROOM);
}
