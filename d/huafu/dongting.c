// dongting.c 东厅
// mlf设计,lks编程

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","东厅");
        set("long",
"这里是花府的东厅，走入东大厅，只见堂首摆放了一套紫檀木的家具
，收拾得纤尘不染，家具上摆放着一些名贵的古董。看来这里的主人是个
很有修养的人士。\n"
	);
	set("valid_startroom",1);
	set("exits",([
		"northwest" : __DIR__"huayuan",
		"south" : __DIR__"dongxiangfang",
	]));
        set("objects",([
                 __DIR__"npc/yin" : 1,
        ]));
	setup();
	replace_program(ROOM);
}
