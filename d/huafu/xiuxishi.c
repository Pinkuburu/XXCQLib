// xiuxishi.c 休息室
// mlf设计，lks编程

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","休息室");
        set("long",
"这里是弟子的休息室，可以让他们在劳累的练功后得到疲劳缓解，这
里并排摆着几张床，看上去很舒适的样子。练了这么长时间倒下来放松一
下倒也不错。\n"
	);
	set("valid_startroom",1);
	set("no_fight",1);
	set("exits",([
		"west" : __DIR__"liangong",
	]));
	set("sleep_room",1);
	setup();
	replace_program(ROOM);
}

