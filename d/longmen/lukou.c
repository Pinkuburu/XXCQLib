// made by lks

inherit ROOM;
#include "/kungfu/class/xuehepai/job.h"

void create()
{
        set("short", "路口");
        set("long", @LONG
这里就是华阳小镇的东路口，冷冷清清的，没有什麽人在附近走动。
往东是一条蜿蜒的小路。西边是一个小镇，镇上的人家并不多，人们都过
着日出而作，日落而息的宁静生活。
LONG );
        set("valid_startroom",1);
        set("exits", ([
                "east" : __DIR__"sroad1",
                "west" : "/d/huayang/hyroad6",
        ]));
        set("class","血河派");
        set("outdoors", "龙门" );
        setup();
}
