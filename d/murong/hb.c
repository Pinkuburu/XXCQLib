// hb.c

#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",GRN"湖边"NOR);
         set("long",
"俗话说："+BLINK HIC+"上有天堂, 下有苏杭"+NOR+"。这里正是大大有名的"+BLINK HIM+"太湖"+NOR+"。湖面绿波上\n"
"漂着一叶叶的"+BLINK HIW+"小舟"+NOR+", 一阵阵悦耳的小曲儿随着湖上的轻风不时漂入你的耳中。\n"
);
         set("outdoors","姑苏慕容");      
         set("exits", ([
             "east" : __DIR__"hb1",
	     "west" : "/d/suzhou/qingshidadao",
]));
         setup();
         replace_program(ROOM);
}
