//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "巨石横滩");
        set ("long", @LONG
这就是著名的巨石横滩了，说是著名一景，其实也不过是一片普通的
河滩，只是因为北面一块巨石堵住了半条江面，才被称为巨石横滩。由于
巨石离河滩很近，所以常有人能上去观景。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"west" : __DIR__"jiangpan2",
		"north" : __DIR__"jushi",
		"east" : __DIR__"jiangpan3",
	]));

        set("outdoors", "zigui");
        setup();
}