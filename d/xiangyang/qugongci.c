//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "屈公祠");
        set ("long", @LONG
这里其实就是秭归镇的南口，因为立有一个为屈原立的牌坊和祠堂而
得名。如今祠堂早已不见了，倒是牌坊一直在。出了秭归镇是一条青石官
道通向远处。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"north" : __DIR__"huiyang2",
		"southeast" : __DIR__"guandao3",
	]));

        set("outdoors", "zigui");
        setup();
}