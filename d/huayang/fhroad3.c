//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "浣花溪畔");
        set ("long", @LONG
这是一条小土路，沿浣花溪向两边延伸，路的西侧可以看到清澈的溪
水，鱼游其中，好不畅快。你的东边就是远近闻名的杜甫草堂，许多孩子
在这里走进走出。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"south" : __DIR__"fhroad2",
		"east" : __DIR__"caotang",
       ]));

        set("outdoors", "xiao");
        setup();
}