// NPC: wenkongzi.c
// Created by Zeus 1999.3.28
// Modified by Zeus 1999.4.3
// Modified Study
// 

#include ansi.h

inherit NPC;

void greeting(object);
void init();
int do_wen(string);

void create()
{
        set_name("温孔子", ({ "wen kongzi", "kongzi", "wen"}) );
        set("gender", "男性" );
        set("age", 30+random(10));
        set("long",
                "温孔子是温家总堂里墨水最多的人。\n");
        set("combat_exp", 10000);
        set("attitude", "friendly");
        set("rank_info/respect", "老师");

        set("qi", 200);
        set("max_qi", 200);
        set("jingli", 300);
        set("max_jingli", 300);

        set_skill("literate", 300);

        add_money("silver", 10);

        setup();
}

void init()
{	
        object ob;

        ::init();
        add_action("do_wen","xue");

        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        say("温孔子看见有人进来，放下手中的书，说道：“这位" + RANK_D->query_respect(ob)
             + "是到我这里来学习的吗？”\n");
}

int do_wen(string arg)
{
        object me;
        int jingli_cost,qi_cost,pot;

        me = this_player();

        if ( !arg || ( arg != "literate" ) )
              return notify_fail("你想干什么？\n");

        jingli_cost = (-1) * random(5);
        qi_cost = (-1) * random(5);
        pot = me->query("potential") - me->query("learned_points");

        if (pot<=0) return notify_fail("你没有潜能了，怎么学习新事物。\n");

        if (me->is_fighting()) return notify_fail("你正在战斗，怎么学习新事物。\n");

        if ( me->query("jingli")+jingli_cost0 || me->query("qi")+qi_cost<0)
        return notify_fail("你的身体太差了，不要学了。\n");

        if ( me->query_skill("literate",1) >= 300 ) 

               return notify_fail("温孔子对$N说：“现在你的学问比我还丰富了。走吧!\n");

        me->add("jingli", jingli_cost);
        me->add("qi", qi_cost);
        me->add("learned_points", 1);

        message_vision("$N向温孔子请教学问。\n", me);
        me->improve_skill("literate", me->query("int")*200+me->query_skill("literate",1)/10);
        return 1;
}
