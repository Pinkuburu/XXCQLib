// Room: 汴梁药局
// By 山猫adx @ 宁波小雪 17:00 99-10-26

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "休息室");
	set("long", @LONG
这里是药王谷专门供弟子休息的地方，这里放着一整排的大床。屋脚
还有几只水桶，里面装满了清水，如果你有容器可以在这里装些水。
LONG );
	set("area", "药王谷");
	set("areb", "休息室");
	set("no_fight", 1);
	set("sleep_room", 1);
	set("resource/water", 1);
	set("exits", ([
		"west" : __DIR__"dongting",
	]));

        create_door("west", "木门", "east", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
