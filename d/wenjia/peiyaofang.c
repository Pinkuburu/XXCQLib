// Room: peiyaofang.c
// Created by Zeus 1999.4.16
// Modified by Zeus 1999.4.16
// 修改长描述。
// 

inherit ROOM;
void create ()
{
        set ("short", "配药房");
        set ("long", @LONG
这里是配药室，当病人在治疗室拿了药方后要来到这里配药
然后才能够服用解毒。这里摆着几个药柜，上面放着各式的药，
有一个温家弟子在配药。
LONG);
        set("area","岭南");
        set("objects", ([
                __DIR__"npc/wenjiadizi" : 1,
        ]));
        set("exits", ([
                "northeast" : __DIR__"huikeshi1",
        ]));
        setup();
        replace_program(ROOM);
}
