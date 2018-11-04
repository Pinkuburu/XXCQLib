// hc.c 

#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",HIW"花丛中"NOR);
         set("long",@long
你信步观赏, 只见花林中除山茶花外更无别样花卉, 连最常见的牵牛花,
月月红, 蔷薇之类也是一朵都无。走出数十丈后, 只见山茶品种渐多, 偶而
也有一两本还算不错, 却也栽种不得其法。
long);
         set("outdoors","姑苏慕容");   
         set("exits",([
         "east" : __DIR__"hc7",
         "south" : __DIR__"hc3",        
]));
         setup();
         replace_program(ROOM);
}
