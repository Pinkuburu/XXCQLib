//Room: kefang.c 客房
//Date by godzilla 1999.10.13


#include <room.h>

inherit ROOM;

void create()
{
         set("short","客房");
         set("long",@long
这是一间客房, 里面摆设简单,左边放着一张床,上面整齐的叠着
被子。这里是专门为来访客人准备的。
long);
         set("no_fight", 1);
         set("sleep_room", 1);
         set("exits",([
             "west" : __DIR__"dating",
]));
 	 setup();
	 replace_program(ROOM);
}
