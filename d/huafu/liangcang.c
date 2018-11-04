// liangcang.c 粮仓
// made by lks

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","粮仓");
        set("long",
"这里就是花府的粮仓，里面满满的装着各种各样的食物。虽然不能和
六分半堂、金风细雨楼这些京城的大帮派相比，但是自给自足还是没问题
的。由于过几天就是花首领的大寿，所以新进了一批酿酒用的高粱、面粉
什么的。你可以找找看。\n"
	);
	set("exits",([
		"west" : __DIR__"caifang",
	]));
	set("valid_startroom",1);
       set("objects",([
             __DIR__"npc/puren" : 1,
       ]));
	setup();
}

/*.
void init()
{
	add_action("do_search","search");
}

int do_search(string arg)
{
	object me;
	object ob;
	me=this_player();
	
        if ( (arg=="高粱") || (arg=="gaoliang") )
	{
		if (ob=present("gaoliang",me))
			return notify_fail("一次只能拿一根。\n");
                message_vision("$N找到一根高粱。\n",me);
		ob=new("/d/huafu/obj/gaoliang");
		ob->move(me);
		return 1;
	}
        if ( (arg=="面粉") || (arg=="mianfen") )
	{
		if (ob=present("mianfen",me))
			return notify_fail("一次只能拿一包。\n");
                message_vision("$N找到一包面粉。\n",me);
		ob=new("/d/huafu/obj/mianfen");
		ob->move(me);
		return 1;
	}
	return notify_fail("这里没有你想要的东西。\n");
}

*/
