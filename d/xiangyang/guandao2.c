//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "青石官道");
        set ("long", @LONG
这是一条平整的青石官道，由于达官贵人走水路去襄阳城一定要经过
这里，所以路也铺得特别的好，北面通往黄河秭归渡口，南面则通向秭归
镇。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"south" : __DIR__"zgnorth",
		"north" : __DIR__"guandao1",
	]));

        set("outdoors", "zigui");
        setup();
}