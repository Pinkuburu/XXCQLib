//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "土路");
        set ("long", @LONG
这是一个黄河边千万个小村庄中的一个，村子很小，甚至连名字也没
有，村中只有四五家居民，家中比较富裕的都搬到附近的秭归镇，只有这
些穷人还住在这里。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"east" : __DIR__"minju1",
		"south" : __DIR__"tulu2",
		"north" : __DIR__"jiangpan3",
	]));

        set("outdoors", "zigui");
        setup();
}