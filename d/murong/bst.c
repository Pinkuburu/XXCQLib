// bushuiting.c

#include <ansi.h>
inherit ROOM;
void create()
{
         set("short", HIC"碧水亭"NOR);
         set("long",@long
这是湖中的一个小亭子，从这望去，可以眺望(tiaowang)到整个湖面的
景色,令人心旷神怡。亭子壁上刻画着江南水乡的宜人风景，令人产生无限
遐想。
long);
         set("exits",([
             "north" : __DIR__"muqiao",
]));
         set("item_desc", ([
             "liang" : "房梁是上好的楠木做的,上面还有十分古怪的字画。\n",
]));
	 setup();
}

void init()
{
	add_action("do_kan", "kan");
}

int do_kan(string arg)
{
	mixed *local;                                                                	
	object me;
	me = this_player();
	local = localtime(time() * 60);
	if(!living(me)) return 0;
	if(me->is_fighting())
		return notify_fail("你现在正在战斗，哪里还有闲心去眺望湖中美景？\n");
	if(local[2] < 5 && local[2] > 20) 
	{
		tell_object(me, "你放眼往湖面上望去，可是一片漆黑你什么都没有看到。\n");
	}
	else
	{
		tell_object(me,"圆圆的一个大湖泊, 看得见湖中央有几个小岛，
小岛上似乎有些小黑点在移动。不知道是什么水鸟儿、野鸭？\n");                                              
	}
	message("vision", "$N双眼直瞪瞪地望着湖边发起呆来。\n", environment(me), ({me}));	
	return 1;
}
