//Room:清馨阁
//Write by godzilla 1999.11.12
#include <room.h>
inherit ROOM;

void create()
{
         set("short","清馨阁");
         set("long",@long
房子不大,布局却非常讲究，四周挂满了名家字画，房间整洁而
干净，这里就是一代大侠方歌吟的房间。
long);
         set("no_fight", 1);
         set("exits",([
             "east" : __DIR__"neitang",
]));
        set("objects",([
                __DIR__"npc/fanggeyin" : 1,
                ]));

         setup();
         replace_program(ROOM);
}

