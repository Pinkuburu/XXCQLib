// Room: peiyaofang.c
// Created by Zeus 1999.4.16
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "配药房");
        set ("long", @LONG
这里是配药室，当病人在治疗室拿了药方后要来到这里配药然后才能
够服用解毒。这里摆着几个药柜，上面放着各式的药，有一个温家弟子在
配药。
LONG);
        set("area","岭南");
        set("valid_startroom", 1);

        set("objects", ([
                __DIR__"npc/wenjiadizi" : 1,
        ]));

        set("exits", ([
                "northeast" : __DIR__"huikeshi1",
        ]));

        setup();
        replace_program(ROOM);
}
