// Room: duku.c
// Created by Zeus 1999.5.12
// Modified by Zeus 1999.5.12
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "毒库");
        set ("long", @LONG
这里是温家小子号非常重要的地方之一，这里收藏了温家的大
部分毒药，许多威震江湖的毒药都收藏在这里。这里也是最危险的
地方之一，因为一不小心就会中毒。
LONG);
        set("area","岭南");

        set("exits", ([
                "south" : __DIR__"cangdushi",
                "down" : __DIR__"cangdudong",
        ]));
        replace_program(ROOM);
        setup();
}