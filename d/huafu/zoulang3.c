// zoulang3.c 走廊3
// mlf设计，lks编程

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","走廊");
        set("long",
"这是连接大厅和西厅的走廊，站在走廊上，你只觉得凉风习习，风窗
露槛，远处鸟语入耳，近处花香扑鼻。你不由得停下脚步，细细欣赏这个
府宅的美景。\n"
	);
	set("valid_startroom",1);
	set("outdoors","huafu");
	set("exits",([
		"east" : __DIR__"dating",
		"west" : __DIR__"xiting",
	]));
	setup();
	replace_program(ROOM);
}
