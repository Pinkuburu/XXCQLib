// ab.c
#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",HIY"岸边"NOR);
         set("long",@long
这里就是曼佗山庄的小岛上了，远处一片片花丛和茂密的柳树林遮挡住
了你的视线。
long);
         set("outdoors","姑苏慕容");
	 set("objects",([
             __DIR__"npc/youcao" : 1,
]));
         set("exits",([
             "south" : __DIR__"liulin",
             "northeast" : __DIR__"hc1",
             "east" : __DIR__"zhuangmen",
]));
         setup();
         replace_program(ROOM);
}
