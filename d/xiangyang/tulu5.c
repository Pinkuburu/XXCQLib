//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "土路");
        set ("long", @LONG
横穿小村庄的土路到了这里就要出村了，除了路东还有一间茅屋，向
南已经看不到茅屋了，路渐渐宽阔起来，人也稍微多了些，远远的已经看
到秭归镇了。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"northeast" : __DIR__"tulu4",
		"southwest" : __DIR__"tulu6",
		"east" : __DIR__"minju5",
        "north" :  "/d/tianyu/damen",
	]));

        set("outdoors", "zigui");
        setup();
}
