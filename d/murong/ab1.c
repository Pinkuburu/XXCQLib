// ab1.c

#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",HIY"岸边"NOR);
         set("long",
"远远看去，只见一个小洲上八九间房间，其中两间是楼房。阁宇中隐约露\n"
"出一个牌坊「"BLINK HIY"听香水榭"NOR"」。\n"
);
         set("outdoors","姑苏慕容");
         set("exits",([
             "south" : __DIR__"shuixie",
]));
         setup();
         replace_program(ROOM);
}
