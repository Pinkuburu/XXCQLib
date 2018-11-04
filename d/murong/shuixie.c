// shuxie.c

#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",HIW"听香水榭"NOR);
         set("long",
"这间房舍小巧玲珑, 颇为精雅。小舍匾额上写着「"HIY"听香水榭"NOR"」四个大字, \n"
"笔致颇为潇洒。东边是一条小路，不知是通往哪里的。再往前走，就到了「\n"
HIW"燕子坞"NOR"」。南边是水榭的后院。\n"
);
         set("exits",([
             "north" : __DIR__"ab1",
             "south" : __DIR__"houyuan1",
]));
	set("objects",([
	__DIR__"npc/azhu" : 1,
	]));
	setup();
        replace_program(ROOM);
}
