// guandao

#include <room.h>

inherit ROOM;

void create()
{       
        set("short", "官道");
        set("long", @LONG
 这是一条蜿蜒不平的官道，只可以让几个人并行。往北通向汴梁
,往南直达嵩山。�
LONG);  
//      set("valid_startroom",1);
//      set("no_steal", "1");
//      set("no_fight", "1");
//      set("sleep_room",1);
        set("exits", ([
                "north" : __DIR__"nanchengmen",
                "southup" : "/d/shaolin/shijie1",
        ]));
/*
        __DIR__"npc/bigwolf" : 2,
]));
*/
        set("area", "汴梁");
        setup();
        replace_program(ROOM);
}

