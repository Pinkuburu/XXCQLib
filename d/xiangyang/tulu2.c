//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "土路");
        set ("long", @LONG
这条路曲曲折折穿村而过，土路边稀稀拉拉的有几家茅草房，向南转
过弯人家密集了一些。路边晒着一些渔网，还有一些打上来的鱼，这些就
是渔民的粮食。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"north" : __DIR__"tulu1",
		"east" : __DIR__"tulu7",
	]));

        set("outdoors", "zigui");
        setup();
}