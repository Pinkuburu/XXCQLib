//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "秭归镇北口");
        set ("long", @LONG
出了秭归镇北口是一条青石大道，一直通往黄河岸边，穷目而望，可
以看到岸边飘舞的旗帜，因为正是赛龙舟的时节，所以这条路上很是热闹
，大家都匆匆向岸边赶去。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"north" : __DIR__"guandao2",
		"south" : __DIR__"chaoyang1",
	]));

        set("outdoors", "zigui");
        setup();
}