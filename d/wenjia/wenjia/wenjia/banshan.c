// Room: banshan.c
// Created by Zeus 1999.6.5
// Modified by Zeus 1999.6.5
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "山路");
        set ("long", @LONG
这里是半山腰，这里的地势比较平坦，聚集了几个温家的弟子，他们
好象在商量什么东西。而向南走就是一条山路，西边也是一条山路。
LONG);
        set("area","岭南");
        set("outdoors", "wenjia");
        set("valid_startroom", 1);

        set("objects", ([
                __DIR__"npc/wenjiadizi" : 4,
        ]));

        set("exits", ([
                "south" : __DIR__"shanlu3",
                "westup" : __DIR__"shanlu4",
        ]));
        setup();
        replace_program(ROOM);
}
