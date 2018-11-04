// Room: 药王谷
// By 山猫adx @ 宁波小雪 17:00 99-10-26

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这是一条鹅卵石铺成的小路，往南通向药王谷山庄的后院。东西两面
各有一间炼丹房。北面有扇竹门，里面饲养了一些动物。
LONG );
	set("area", "药王谷");
	set("areb", "小路1");
	set("no_fight", 1);
	set("exits", ([
		"north" : __DIR__"xiaolu2",
		"south" : __DIR__"houyuan",
		"west" : __DIR__"liandan1",
		"east" : __DIR__"liandan2",
	]));

        create_door("north", "竹门", "south", DOOR_CLOSED);
	setup();
}

int valid_leave(object me, string dir)
{
        if( dir=="north" 
        && me->query("party/party_name")!=HIB"药王谷"NOR)
                return notify_fail("那里只有药王谷中人才能过去。\n");
        return ::valid_leave(me, dir);
}
