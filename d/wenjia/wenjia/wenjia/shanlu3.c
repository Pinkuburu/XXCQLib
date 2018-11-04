// Room: shanlu3.c
// Created by Zeus 1999.6.5
// Modified by Zeus 1999.6.5
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "山路");
        set ("long", @LONG
一条人由人踩出来的山路，这里已经是半山腰了，再从这里上去就是
温家的总堂了。不时看见温家的弟子从这里经过，他们的神情紧张。当他
们走过你身边的时候你会觉得有一股奇异的气味。
LONG);
        set("area","岭南");
        set("outdoors", "wenjia");

        set("exits", ([
                "southdown" : __DIR__"shanlu2",
                "north" : __DIR__"banshan",
        ]));
        setup();
        replace_program(ROOM);
}
