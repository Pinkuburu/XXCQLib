//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "秭归镇东口");
        set ("long", @LONG
出了秭归镇东口是一条小土路，由于富人们很少来这边，所以也就没
有人来修路。沿土路可以到一个小村子，向西进入秭归镇则是小镇的金银
街，金银钱庄就在这条街上。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"east" : __DIR__"tulu6",
		"west" : __DIR__"jinyin3",
	]));

        set("outdoors", "zigui");
        setup();
}