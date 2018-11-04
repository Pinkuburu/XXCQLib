// Room: 药王谷
// By 山猫adx @ 宁波小雪 17:00 99-10-26

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这是一条鹅卵石铺成的小路，往南通向药王谷山庄的后院。东面是一间
饲养场，西面是屠宰场。
LONG );
	set("area", "药王谷");
	set("areb", "小路2");
	set("no_fight", 1);
	set("exits", ([
		"south" : __DIR__"xiaolu1",
		"west" : __DIR__"syang",
         "north" : __DIR__"syang1",
		"east" : __DIR__"tuzai",
	]));

        create_door("south", "竹门", "north", DOOR_CLOSED);
	setup();
}

int valid_leave(object me, string dir)
{
        if( dir=="south" 
        && me->query("party/party_name")!=HIB"药王谷"NOR)
                return notify_fail("那里只有药王谷中人才能过去。\n");
        return ::valid_leave(me, dir);
}
