//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "金银钱庄");
        set ("long", @LONG
金银钱庄是附近最大的一家钱庄，由于他的后台老板是权利帮的人，
所以没人敢惹，不过天下的银号都是通存通取，存钱倒还没有问题。一个
中年人做在柜台后，手中把玩着一竿金秤。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"south" : __DIR__"jinyin2",
		"north" : __DIR__"jyqz2",
	]));

	set("objects", ([
		__DIR__"npc/cheng": 1,
	]));

        setup();
}
