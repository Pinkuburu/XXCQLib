//changan city

#include <ansi.h>
inherit ROOM;
#include "/kungfu/class/xuehepai/job.h"

void create ()
{
        set ("short", "华阳镇西街");
        set ("long", @LONG
你所站的这条街是华阳镇的主道，贯穿小镇东西，几乎所有的店铺都
在这条街上。而现在你的南首就是方圆十里之内唯一的一家杂货店，不光
是小镇的居民，就是周围村镇的人也要到这里来买东西，路北则是一家打
铁铺。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"west" : __DIR__"hyroad2",
		"south" : __DIR__"hyzahuo",
		"east" : __DIR__"hyroad4",
		"north" : __DIR__"hytiepu",
       ]));

        set("outdoors", "huayang");
        setup();
}
