// damen。c  大门
// god

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short","权力帮大门");
	set("long",@LONG
这里是权力帮的大门，大门上方跳出四角飞檐，两侧立有四根大理石
柱，柱身纹有图腾底案。大门上正中悬挂一块金匾，刻有“君临天下”四
个血红大字，笔力遒劲.
LONG);
	set("valid_startroom",1);
	set("outdoors","归昧");
	set("exits",([
        	"north" : __DIR__"qilingtang",
            "south" : "/d/xiangyang/jyqz",
	]));
        set("objects",([
           __DIR__"npc/bangzhong" : 2,
           ]));
	setup();
              replace_program(ROOM);
}
