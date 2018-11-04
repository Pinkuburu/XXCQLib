// nanchengmen.c 

#include <room.h>

inherit ROOM;

void create()
{       
        set("short", "西城门");
        set("long", @LONG
 这是西城门，城门正上方刻着“西门”两个楷书大字。
向西走就到了姊归镇 。
LONG);  
//      set("valid_startroom",1);
//      set("no_steal", "1");
//      set("no_fight", "1");
//      set("sleep_room",1);
        set("exits", ([
                "west" : "/d/room/playtown/guandao1",
                "east" : __DIR__"huangkudajie3",
        ]));
//      set("objects", ([
//              "/clone/weapon/changjian" : 4]));
        set("area", "汴梁");
        setup();
        replace_program(ROOM);
}
