//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "睡房");
        set ("long", @LONG
这是一间昏暗的房间，房间仅有的一扇窗户还常年拉着帘。屋内是一
张竹铺，只能睡两个人，借着隐隐的光亮可以看到床上还有空地。你没心
思细观察，忙找了个地方上床躺下来。
LONG);
	set("valid_startroom", 1);
         set("sleep_room", 1);

        set("exits", 
        ([
		"west" : __DIR__"jyqz2",
	]));

        setup();
}
