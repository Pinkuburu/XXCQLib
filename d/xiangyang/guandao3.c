//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "青石官道");
        set ("long", @LONG
秭归镇是襄阳周围诸多小镇中的一个，平整的青石官道从黄河边的秭
归码头一直延伸到襄阳城。不时的有游人、马车匆匆路过。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"northwest" : __DIR__"qugongci",
		"southeast" : __DIR__"guandao4",
	]));

        set("outdoors", "zigui");
        setup();
}