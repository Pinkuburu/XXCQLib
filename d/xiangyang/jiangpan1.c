//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "长江江畔");
        set ("long", @LONG
走在长江江畔，俯瞰着滚滚长江，甚是壮观。现在正值五月五赛龙舟
，许多襄阳城的富人家都乘车来这里看龙舟，而秭归镇的居民更是全体出
动，赛龙舟的赛龙舟，做生意的做生意。你的西面就是秭归码头，南面则
有一家河神庙。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"west" : __DIR__"zgmatou",
		"east" : __DIR__"jiangpan2",
		"south" : __DIR__"heshen",
       ]));

        set("outdoors", "zigui");
        setup();
}