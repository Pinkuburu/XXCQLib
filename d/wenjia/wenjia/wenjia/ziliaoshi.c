// Room: ziliaoshi.c
// Created by Zeus 1999.4.8
// Modified by Zeus 1999.7.22
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "资料室");
        set ("long", @LONG
这里是实验室旁边的资料室，这里储存了各种毒药的制作方法。包括
了相思蜂雨中等厉害的毒药。不时有人从南面的实验室来这里拿资料。
LONG);
        set("area","岭南");
        set("valid_startroom", 1);
        set("poisonkbook_count", 1);

        set("exits", ([
                "south" : __DIR__"shiyanshi",
        ]));

        setup();
        replace_program(ROOM);
}
