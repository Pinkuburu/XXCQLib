//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "金银街");
        set ("long", @LONG
本来这条街的名字叫落阳街，是以秭归镇又名三阳镇，但是自从权利
帮在这里开了家金银钱庄后，这条街也就给改名为金银街了。路南是一家
珠宝店，也是权利帮开的。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"east" : __DIR__"jinyin2",
		"west" : __DIR__"zgcs",
	]));

        set("outdoors", "zigui");
        setup();
}