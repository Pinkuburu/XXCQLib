// 山猫ADX by snow 99-12-4

#include <ansi.h>
inherit ROOM;

void create ()
{
	set("short",  "官道");
	set("long",
"这是一条宽阔笔直的官道，黄土路面，足可容得下十马并驰。往北通向\n"
"朝廷的皇城，往南通向汴梁城。西边是一座高耸入云的高山，世人都称之为\n"
WHT"“神雪山”"NOR+"新手都必须在这里学习基本是生存技能。\n"
);
	set("exits",  ([
//		"north"  :  "/d/chaoting/chengmeng",
		"westup"  :  __DIR__"shanjiao",
		"east"  :  __DIR__"road7",
	]));
	set("outdoors",  1);
	setup();
	replace_program(ROOM);
}
