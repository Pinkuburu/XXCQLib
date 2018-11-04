// caifang.c 柴房
// mlf设计,lks编程

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","柴房");
        set("long",
"这里是花府的柴房，这里看上去要比别人的柴房干净多了，这是由于
发梦二党的弟子经常在这里帮忙的缘故。角落里放着一堆柴，柴下好象有
什么东西。\n"
	);
	set("valid_startroom",1);
	set("exits",([
		"west" : __DIR__"chanting",
                "east" : __DIR__"liangcang",
	]));
	set("book_count",1);
     set("chai_moved",1);
	setup();
}

void init()
{
	add_action("do_move","move");
	add_action("do_pull","pull");
}

int do_move(string arg)
{
	object ob=this_player();
	object where=environment(ob);
	if (arg!="柴") return 0;
    if (!where->query("chai_moved"))
                return notify_fail("柴已经被移开了。\n");
    set("chai_moved",0);
        return notify_fail("柴被你移开了,出现了一块铁板。\n");
}

int do_pull(string arg)
{
	object ob,me=this_player();
       object where;
        where=environment(me);
	if (arg!="铁板") return 0;
    if( where->query("chai_moved") )
                return notify_fail("你周围没有这东西。\n");
        if((int)me->query_str()<22)
        	return notify_fail("你力气太小,没法拉起铁板。\n");
        message_vision("$N使出吃奶的力气，将铁板向上拉起。\n",me);
        if (!(where->query("book_count")))
              return notify_fail("下面什么都没有。\n");
        ob=new(__DIR__"obj/sword-book");
        ob->move(me);
        message_vision(HIG"$N发现了一本书！\n"NOR,me);
        where->set("book_count",0);
        return 1;
}

	
