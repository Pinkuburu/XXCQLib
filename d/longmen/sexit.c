
inherit ROOM;
#include "/kungfu/class/xuehepai/job.h"
void create()
{
        set("short", "南路口");
        set("long", @LONG
这里再往南走，是通向龙门石窟的山路。听说“血河派”就创建在
那里，最近武林大乱，联合起来要攻打血河派。所以没几把刷子就不要
上山，以免遭来杀身之祸。北面就是龙门小镇。
LONG );
        set("valid_startroom",1);
        set("outdoors","龙门");
        set("class","血河派");
        set("exits", ([
                "south"  : __DIR__"xiaolu1",
                "north"  : __DIR__"nanjie",
        ]));
//        set("no_clean_up", 0);
        setup();
}

