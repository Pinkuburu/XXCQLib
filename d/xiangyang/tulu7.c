//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "土路");
        set ("long", @LONG
这是横穿小村庄的土路，土路边稀稀拉拉的有几家茅草房，偶尔有一
只鸡跑过，也是没精打采。路边晒着一些渔网，还有一些打上来的鱼，这
些就是渔民的粮食。再往南人家渐渐多了些。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"southeast" : __DIR__"tulu3",
		"west" : __DIR__"tulu2",
	]));

        set("outdoors", "zigui");
        setup();
}