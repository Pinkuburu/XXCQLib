//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "潮阳街");
        set ("long", @LONG
虽然秭归镇只是一个小镇，但确是五脏具全，比如路西就是一家驿站
，经常有船休息在秭归码头，于是客人便休息到这家客栈，路东是一家普
通的民居。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"north" : __DIR__"chaoyang1",
		"south" : __DIR__"zgcs",
	]));

        set("outdoors", "zigui");
        setup();
}