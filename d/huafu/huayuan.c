// huayuan.c 花园
// mlf设计，lks编程

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","花园");
        set("long",
"这里是花府里面的花园，由于发梦二党弟子众多，所以这里不乏各地
的奇花异草，四季常开，争奇斗妍。这里往北就是花府的大厅。往南可以
望见街上的人流。\n"
	);
	set("outdoors","huafu");
	set("exits",([
                "out" : __DIR__"menfang",
		"north" : __DIR__"dating",
		"southeast" : __DIR__"dongting",
		"west" : __DIR__"zaofang",
	]));
	set("valid_startroom",1);
	setup();
	replace_program(ROOM);
}
