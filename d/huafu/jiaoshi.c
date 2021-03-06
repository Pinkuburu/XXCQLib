// jiaoshi.c  窖室
// made by lks

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","窖室");
        set("long",
"这里就是花府的酿酒室，由于酿酒的工艺流程很复杂。所以这里分工
很细，人也特别多些。但是从忙碌的现场来看，还是觉得人手不够。尤其
过几天就是花首领大寿，就缸窑的那几瓶酒是不够的。\n"
	);
	set("exits",([
		"out" : __DIR__"zaofang",
	]));
	set("valid_startroom",1);
        set("objects",([
                 __DIR__"npc/niangjiushi" : 1,
        ]));
	setup();
}

void init()
{
	add_action("do_zhuang","zhuang");
	add_action("do_fire","fire");
}

int do_zhuang(string arg)
{
	object obb;
	object me;
	me=this_player();
	
                 if (query("kaishi"))
                         return notify_fail("已经有人在酿酒了，你稍等一会。\n");
        if ( (arg=="醅子") || (arg=="peizi") )
	{
		if ( !obb=present("peizi",me) )
			return 0;
		message_vision("$N将醅子装入锡锅中，均匀平铺约三四寸厚。\n",me);
		me->set_temp("zhuangpeizi",1);
		destruct(obb);
                 set("kaishi",1);
               remove_call_out("cut");
                      call_out("cut",30);
		return 1;
	}
        if ( (arg=="高粱饭") || (arg=="gaoliangfan") )
	{
		if (!obb=present("gaoliangfan",me) ) 
			return 0;
		message_vision("$N将拌匀的高粱饭装入窖中，压紧，再涂泥于上，以隔绝空气。\n",me);
		me->set_temp("zhuangfan",1);
		destruct(obb);
		return 1;
	}
	return notify_fail("你要把什么东西装到窖里面？\n");
}

int do_fire(string arg)
{
	object me;
	me=this_player();
	
        if ( (arg!="窖") && (arg!="锅") && (arg!="jiao") && (arg!="guo")  )
		return notify_fail("你要给什么东西加温？\n");
        if ( (arg=="窖") || (arg=="jiao") )
	{
		if ( me->query_temp("zhuangfan") )
		{
			int i;
                        i=(12-((int)me->query("max_neili")/100));
			if ( (int)me->query("neili") <=100)
			{
				message_vision("$N拼命的拉动着风箱，火苗窜得老高。\n",me);
				me->set_temp("firejiao",1);
				remove_call_out("del_job");
				call_out("del_job",i);
				return 1;
			}
                        else {
                            me->add("neili",-(10+random(10)));
                        }
			message_vision("$N运气于掌，催动着火苗。\n",me);
			me->set_temp("firejiao",1);
			remove_call_out("del_job");
			call_out("del_job",i);
			return 1;
		}
		
		tell_object(me,"你还没把高粱饭装进窖中。\n");
                return 1;
	}
        if ( (arg=="锅") || (arg=="guo") )
	{
		if ( me->query_temp("zhuangpeizi") )
		{
			int i;
                        i=(12-((int)me->query("max_neili")/100));
			if ( (int)me->query("neili") <=100)
			{
				message_vision("$N拼命的拉动着风箱，火苗窜得老高。\n",me);
				me->set_temp("fireguo",1);
				remove_call_out("del_job");
				call_out("del_job",i);
				return 1;
			}
                        else {
                            me->add("neili",-(10+random(10)));
                        }
			message_vision("$N运气于掌，催动着火苗。\n",me);
			me->set_temp("fireguo",1);
			remove_call_out("del_job");
			call_out("del_job",i);
			return 1;
		}
		
		tell_object(me,"你还没把醅子装进锡锅中。\n");
                return 1;
	}
}
	
int del_job()
{
	object ob;
	object me;
	me=this_player();
	
	if ( me->query_temp("firejiao") )
	{
		message_vision("$N得到了一个醅子！\n",me);
		ob=new("/d/huafu/obj/peizi");
		ob->move(me);
               me->add("qi",-(10+random(10)));
              me->delete_temp("zhuangfan");
              me->delete_temp("firejiao");
		return 1;
	}
	if ( me->query_temp("fireguo") )
	{
		message_vision("$N看到酒露慢慢的流满了一坛。高兴的跳了起来。\n",me);
		ob=new("/d/huafu/obj/jiuyunjiu");
		ob->move(me);
               me->add("qi",-(10+random(10)));
              me->delete_temp("zhuangpeizi");
              me->delete_temp("fireguo");
                  set("kaishi",0);
		return 1;
	}
	return 0;
}

void cut()
{
          if (query("kaishi"))
                     set("kaishi",0);
                return;
}

