inherit ROOM;

#include <ansi.h>
void create()
{
      set("short","关口");
      set("long",@LONG
这里被临时搭建了一个关卡，一个中年人在指挥血河派弟子对来往游客
进行检查，百姓可以过，江湖人士一律不许通过。几个江湖人士还正在和那
个中年人理论。看来，血河派封山了，正在戒严。
LONG);
	set("valid_startroom",1);
           set("renshu",0);
	set("objects",([
                 "/kungfu/class/xuehepai/huwei1" : 1,
	]));
	set("exits",([
                "west"  : __DIR__"guanka",
		"east"  : __DIR__"shanjiao",
	]));
	set("outdoors", "龙门");

	setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam,party;
        myfam=(mapping)me->query("family");
        party=(mapping)me->query("party");

              if (me->query_temp("shouwei"))
                     return notify_fail("你现在正在守卫，不能到处走动。\n");
if (((myfam && myfam["family_name"] != "血河派") || (!myfam && party)) && (dir=="east") )
        {
                if (present("huwei", environment(me)))
                        return notify_fail("护卫伸手拦住你谦声说道：血河派已经戒严了，不容江湖人士擅自入内，\n若非拜师的话"
                                + RANK_D->query_respect(me) +"还是请回去吧，免得自讨没趣。\n");
        }

        return ::valid_leave(me, dir);
}

void init()
{
         add_action("do_shouwei","shouwei");
}

int do_shouwei(object me)
{
         me=this_player();

              if (query("renshu")>=4)
              return notify_fail("这里最多只要三个人守。\n");
            if (!(me->query_temp("xhjob_start")))
                   return notify_fail("你没有被指派到这里守卫。不要多管闲事！\n");
            if (me->query_temp("shouwei"))
                   return notify_fail("你正在守卫血河派的关卡通道。\n");
          message_vision(HIC"$N抖擞精神，开始打量身边的每一个行人。\n"NOR, me);

         me->apply_condition("xhquest", 6);
              add("renshu",1);
            me->set_temp("shouwei",1);
          return 1;
}
