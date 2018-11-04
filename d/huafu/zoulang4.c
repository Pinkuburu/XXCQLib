// zoulang4.c 走廊4
// mlf设计,lks编程

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","走廊");
        set("long",
"站在走廊上，从这往东边及西边而去，在东边是一间大房子，里面传
来阵阵叱喝的声音，那里就是花府的练功房。发梦二党的弟子都在此处练
习武技。\n"
	);
	set("valid_startroom",1);
	set("outdoors","huafu");
	set("exits",([
		"west" : __DIR__"dating",
		"east" : __DIR__"liangong",
	]));
	setup();
	replace_program(ROOM);
}

	
