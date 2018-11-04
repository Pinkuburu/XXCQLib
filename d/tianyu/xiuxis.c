//Room: kefang.c 客房
//Date by godzilla 1999.10.13


#include <room.h>

inherit ROOM;

void create()
{
         set("short","休息室");
         set("long",@long
这是一间休息室，专门为闭关修炼的弟子准备的。
long);
            set("no_fight", 1);
         set("resource/water", 1);
         set("sleep_room", 1);
         set("exits",([
             "west" : __DIR__"lgs",
]));
         set("objects", ([
         __DIR__"obj/hulu" : 1,
         __DIR__"obj/meihua-zaoya" : 3,
         ]));

 	 setup();
}
void init()
{
	add_action("do_quit","quit");
}
int do_quit()
{
       object me=this_player();
       tell_object(me,"闭关时不能退出！\n");
       return 1;
}
