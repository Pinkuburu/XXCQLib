// nanchengmen.c 

#include <room.h>

inherit ROOM;

void create()
{       
        set("short", "南城门");
        set("long", @LONG
 这是南城门，城门正上方刻着“南门”两个楷书大字。
北方是一片崇山峻岭，一条黄土小径在山里蜿蜒而上。
LONG);  
//      set("valid_startroom",1);
//      set("no_steal", "1");
//      set("no_fight", "1");
//      set("sleep_room",1);
        set("exits", ([
                "north" : __DIR__"nandajie1",
                "south" : __DIR__"guandao10",
]));
           set("objects", ([
           "d/bianliang/npc/youke" : 2, 
]));
        replace_program(ROOM);
}
