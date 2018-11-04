// beiengmen.c 

#include <room.h>

inherit ROOM;

void create()
{       
        set("short", "北城门");
        set("long", @LONG
 这是北城门，城门正上方刻着“北门”两个楷书大字。
北方就是著名的药王谷。
LONG);  
//      set("valid_startroom",1);
//      set("no_steal", "1");
//      set("no_fight", "1");
//      set("sleep_room",1);
        set("exits", ([
                "north" : "/d/yaowang/shanlu1",
                "south" : __DIR__"huangshanjie3",
                "northwest"  :  "/d/newbei/road1",
        ]));
//      set("objects", ([
//              "/clone/weapon/changjian" : 4]));
        set("area", "汴梁");
        setup();
        replace_program(ROOM);
}

