// houyuan1.c
#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",HIW"后院"NOR);
         set ("long",@long
这是水榭的后院，院中假山水石，无一不透出江南别具一格的风格。南
边就是举世闻名的燕子坞了。东面是一座通向湖中小岛的木桥。
long);
         set("outdoors","姑苏慕容");
         set("exits",([
             "north" : __DIR__"shuixie",
             "south" : __DIR__"yanziwu",
             "east"  : __DIR__"muqiao",
]));
         setup();
         replace_program(ROOM);
}
