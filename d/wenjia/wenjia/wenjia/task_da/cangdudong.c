// Room: xiaojing.c
// Created by Zeus 1999.5.12
// Modified by Zeus 1999.5.12
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "藏毒洞");
        set ("long", @LONG
温家很少人知道有这个地方，因为这里存放的都是温家的至宝。
收藏在这里的有好象“相识蜂雨中”等著名毒药的成品。得到一样
就可以威震江湖。
LONG);
        set("area","岭南");

        set("exits", ([
                "up" : __DIR__"duku",
        ]));
        replace_program(ROOM);
        setup();
}