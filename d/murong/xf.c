// xf.c

#include <ansi.h>
inherit ROOM;

void create()
{
         set("short",MAG"厢房"NOR);
         set ("long",@long
这是一间厢房, 里面摆设简单, 只有一张床, 一张书桌和一把椅子。
long);
         set("no_fight", 1);
         set("sleep_room", 1);
         set("exits",([
             "west" : __DIR__"houyuan",
]));
 	 setup();
	 replace_program(ROOM);
}
