// Room: shandi.c
// Created by Zeus 1999.6.5
// Modified by Zeus 1999.6.5
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "山底");
        set ("long", @LONG
这里是岭南山脉的底部，四处都是茂密的森林，只有一条山路上山。
据说这里经常有土匪出没，可要小心一点。西边是北江的渡口，从那里可
以坐船去到桂林。
LONG);
        set("area","岭南");
        set("outdoors", "wenjia");

        set("exits", ([
                "west" : __DIR__"gangkou",
                "southup" : __DIR__"shanlu1",
        ]));
        setup();
        replace_program(ROOM);
}
