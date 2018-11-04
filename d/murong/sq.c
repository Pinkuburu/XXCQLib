// sq.c

#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",HIW"小石桥"NOR);
         set("long",@long
这是一座小小的白石拱桥。桥下碧绿的湖水正荡着微波。远处的湖面上
传来阵阵歌声，不远处两只鸳鸯在一起戏水，岸边的柳树随着湖面上吹来的
微风时不时地摇摆着。
long);
// will add a npc to ask chuan
          set("outdoors","姑苏慕容");
          set("exits", ([
           "south" : __DIR__"matou",
           "northwest" : __DIR__"hb2",
]));
          replace_program(ROOM);
          setup();
}
