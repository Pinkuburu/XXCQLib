// zaofang.c  糟坊
// made by lks

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","糟坊");
        set("long",
"刚一进来，一股浓烈的酒香扑鼻而来。花枯发以酿酒著名于世，这里
就是花府造酒的地方。糟坊分为缸窑和窖室，以为高粱饭发酵之用。此时
正值花枯发大寿，所以这里特别忙碌。\n"
	);
	set("exits",([
		"east"  : __DIR__"huayuan",
		"down" : __DIR__"gangyao",
		"enter"  : __DIR__"jiaoshi",
	]));
	set("valid_startroom",1);
	setup();
}

int valid_leave(object me,string dir)
{
            object ob;

            if ( (!(ob=present("gaoliangfan",me))) && (dir=="enter") )
            return notify_fail("你原料还没做好，进去也是白搭。\n");

            return ::valid_leave(me,dir);
}

