// Room: lijiangbian1.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "漓江边");
        set ("long", @LONG
漓江江水在旁边的悬崖下飞奔，而这里东南边是一座铁索桥，走过铁
索桥可以到达桂林。这里属于两广地区与四川交界的地方，往南走是一条
驿道，可以通往四川。
LONG);
        set("area","桂林");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("exits", ([
                "west" : __DIR__"yidao1",
                "southeast" : __DIR__"tiesuo",
        ]));
        setup();
        replace_program(ROOM);
}

