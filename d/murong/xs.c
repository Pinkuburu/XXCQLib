// xs.c

#include <ansi.h>
inherit ROOM;

void create()
{
         set("short", HIY"小舍"NOR);
         set("long",
"这间房舍小巧玲珑, 颇为精雅。小舍匾额上写着「"BLINK HIY"琴韵"NOR"」两字笔致,\n"
"致颇为潇洒。远处的小屋露出一檐屋角。东西两边各有一条小径不知通\n"
"向哪里。\n"
);
         set("exits", ([
             "east" : __DIR__"xj1",
	     "north" : __DIR__"xd",
             "west" : __DIR__"tyj",
]));
         set("objects",([
             __DIR__"npc/bao" : 1,          
]));
         setup();
         replace_program(ROOM);
}

