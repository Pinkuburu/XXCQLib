//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "金银街");
        set ("long", @LONG
看着街北的金银钱庄的金匾你就知道，秭归镇最著名的金银钱庄就在
这里。尽管钱庄仗着权利帮的支撑称王称霸，但由于这里只有这么一家钱
庄，所以生意还是不错的。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"east" : __DIR__"jinyin3",
		"west" : __DIR__"jinyin1",
		"north" : __DIR__"jyqz",
	]));

        set("outdoors", "zigui");
        setup();
}