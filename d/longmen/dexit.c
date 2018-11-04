
inherit ROOM;
#include "/kungfu/class/xuehepai/job.h"
void create()
{
        set("short", "东路口");
        set("long", @LONG
从这里再往东走，就到了龙门小镇。这里虽然人不是很多，但是却
什么都有，真是“麻雀虽小，五脏俱全。”最近由于血河派惹恼了武林
势力，江湖门派都联合起来围剿血河派，这反而刺激了这个小镇的发展
什么酒店，客栈都热闹的开张了。
LONG );
        set("valid_startroom",1);
        set("outdoors","龙门");
        set("class","血河派");
        set("exits", ([
                "west"  : __DIR__"qsroad1",
                "east"  : __DIR__"xijie",
        ]));
//        set("no_clean_up", 0);
        setup();
}


