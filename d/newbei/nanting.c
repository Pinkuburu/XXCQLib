//By adx by snow 99-12-5

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",WHT"神雪南侧厅"NOR);
	set("long",
"你走进一间不大的房间这里是神雪山的南侧厅，该一般都在这里授徒,\n"
 "如果你想学什么武功可以在这里向教习学习武功"+HIC"（xue jiaoxi xxxx）。\n"NOR
"当你离开这里以后你只能向师父学武功，所以你要先拜师"+HIC"（bai xxxx）\n"NOR
 "你如果要离开这座神雪山必须先得到教习的同意"+HIC"(fight jiaoxi).\n"NOR
	);
        set("exits", ([
                "north":__DIR__"dating",
        ]));
        set("objects",([
                __DIR__"npc/jiaoxi":1,
                ]));
	setup();
        replace_program(ROOM);
}
