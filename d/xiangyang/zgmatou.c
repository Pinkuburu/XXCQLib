//changan city

#include <ansi.h>
#include <room.h>
inherit MATOU;

void create ()
{
        set ("short", "秭归码头");
        set ("long", @LONG
这里就是秭归码头了，几艘泊在码头的乌篷船都看不到船家。如果你
要雇船就喊一下船家(gu chuan)。秭归背依高山，面临长江，景色壮丽，
这是屈原故里，所以每年五月初五，更是热闹，龙舟塞满江上。这街上来
来往往的恐怕都是去看龙舟的了。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"east" : __DIR__"jiangpan1",
		"west" : __DIR__"jiangpan4",
		"south" : __DIR__"guandao1",
        ]));

        set("outdoors", "zigui");
        setup();
}