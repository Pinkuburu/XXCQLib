// Room: yixiantiannei.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "一线天内");
        set ("long", @LONG
“一线天”果然名不虚传，从这里向上看两旁高耸的峭壁间只露出一
条白线，两旁的峭壁上长满了老山藤，乍一看就象是几条大蛇缠在树上。
一阵风吹过，四周发出了奇怪的声音，你感到背上有些寒意。还是快点走
吧。
LONG);
        set("area","飞鱼");
        set("outdoors", "feiyu");

        set("objects", ([
                __DIR__"npc/feiyudizi" : 1,
        ]));

        set("exits", ([
                "northup" : __DIR__"yixiantian",
                "southdown" : __DIR__"yixiantiannei2",
        ]));
        setup();
        replace_program(ROOM);
}
