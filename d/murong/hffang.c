// hffang.c

#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",BLU"花肥房"NOR);
         set ("long",@long
只见一个弓腰曲背的老婆子手里拿着一柄雪亮的长刀, 身旁一锅沸水, 
煮得直冒热气。
long);
         set("exits",([
         "west" : __DIR__"hxlou",
]));
         set("objects",([
         __DIR__"npc/yan" : 1,
]));       
	setup();
	replace_program(ROOM);
}
