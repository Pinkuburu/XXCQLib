// Room: shufang.c
// Created by Zeus 1999.4.16
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "书房");
        set ("long", @LONG
这里死字号的首脑温丝卷的书房。温丝卷在这里处理死字号的大事，
并且派出杀人的人物，当然你也可以在这里领任务去做，不过要经过考
验才可以领任务。经过西面的门可以回到会客室。
LONG);
        set("area","岭南");
        set("valid_startroom", 1);

        set("objects", ([
                __DIR__"npc/wensijuan" : 1,
        ]));
        set("exits", ([
                "west" : __DIR__"huikeshi2",
        ]));

        setup();
        replace_program(ROOM);
}
