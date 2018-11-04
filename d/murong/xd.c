// xd.c
#include <ansi.h>

inherit ROOM;  

void create()
{
         set("short",HIB"小岛边"NOR);
         set("long",@long
你一跨上岸去, 见疏疏落落四五座房舍, 建造在一个不知名的小岛或半
岛上。岛上树木葱绿，亭宇轩榭错落有秩，处处飘来一阵幽香。这里的一切
无一不透出江南水秀山清，建筑小巧别致的特色。
long);
         set("exits", ([
             "south" : __DIR__"xs",                    
]));                                        
	set("outdoors", "姑苏慕容");                         
         setup();
         replace_program(ROOM);
}
