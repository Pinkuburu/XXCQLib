//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "飞花桥畔");
        set ("long", @LONG
现在你就站在四川浣花溪畔，你的东面是方圆五里之内过浣花溪的唯
一一座桥“飞花桥”，西面则是一条青石阶，从青石阶上去就可以到浣花
萧家了。这里还可以沿溪向南北走去，北面溪畔有一些浣花的丫鬟在洗衣
服，南面则隐隐传来了读书声。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"westup" : __DIR__"hhroad",
		"eastup" : __DIR__"feihuaqiao",
		"north" : __DIR__"hhxroad3",
		"south" : __DIR__"hhxroad2",
       ]));

        set("outdoors", "xiao");
        setup();
}