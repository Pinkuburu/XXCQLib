//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "华阳南巷");
        set ("long", @LONG
小巷并不很长，三面都是民居，由于小巷很窄，阳光很是不足，阴暗
的角落又脏又乱，偶尔有人从屋内出来，但基本上安安静静。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"north" : __DIR__"hycs",
        ]));

        set("outdoors", "huayang");
        setup();
}
