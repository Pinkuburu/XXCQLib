//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "土路");
        set ("long", @LONG
这是一条两人宽的土路，从来是不走车的，只有浣花弟子和去浣花溪
畔杜甫草堂的人才会走这条路。路边有一些稀稀拉拉的花草，路的西北就
通向浣花溪，往南则进入了一片树林，据说里面有强人打劫的。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"northwest" : __DIR__"feihua",
		"south" : __DIR__"treeroad1",
       ]));

        set("outdoors", "huayang");
        setup();
}