// Room: 汴梁药局
// By 山猫adx @ 宁波小雪 17:00 99-10-26

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "休息室");
	set("long", @LONG
这里是回春堂的休息室，这里是让药局跑堂和医师休息的地方。
房间内放着整排的床铺，如果你累了，可以在这里睡一会儿。
LONG );
	set("area", "汴梁东");
	set("areb", "回春堂");
	set("no_fight", 1);
	set("sleep_room", 1);
	set("resource/water", 1);
	set("exits", ([
		"east" : __DIR__"beiting",
	]));

        create_door("east", "木门", "west", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
