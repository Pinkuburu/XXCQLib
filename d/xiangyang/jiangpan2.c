//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "长江江畔");
        set ("long", @LONG
走在长江江畔，俯瞰着滚滚长江，甚是壮观。这段长江流得甚是平缓
，许多龙舟和彩船充斥江面，看来比赛快开始了。你的东面就是有名的巨
石横滩，西面则通向秭归码头。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"west" : __DIR__"jiangpan1",
		"east" : __DIR__"hengtan",
       ]));

        set("outdoors", "zigui");
        setup();
}