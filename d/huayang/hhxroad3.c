//changan city

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "浣花溪畔");
        set ("long", @LONG
这是一条小土路，沿浣花溪向两边延伸，路的西侧是满坡的野山花，
煞是好看，路东溪畔有一块大大的平石，上面很是光滑，几个浣花丫鬟围
着这块石头在洗衣服，她们边洗边说笑着，好不热闹。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"south" : __DIR__"hhxroad1",
		"north" : __DIR__"hhxroad4",
        ]));

	set("hhjob", 1);
        set("outdoors", "xiao");
        setup();
}