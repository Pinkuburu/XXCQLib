//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "稻田");
        set ("long", @LONG
这是一片典型南方的稻田，大概有两、三亩的样子，由于年景不好，
看来今年的收成也不怎么好，好在这里的人一般以打渔为生。稻田的北面
好像有一户人家。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"west" : __DIR__"tulu3",
		"north" : __DIR__"minju2",
		"south" : __DIR__"maitian2",
	]));

        set("outdoors", "zigui");
        setup();
}