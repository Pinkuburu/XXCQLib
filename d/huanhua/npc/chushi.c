//Npc 厨师
//by 

#include <ansi.h>

string ask_job();

inherit NPC;

void create()
{
        set_name("厨师", ({"chu shi","chu","shi",}));
        set("long",
                "这是位胖胖的中年人，大概是因为长年烧饭作菜的缘故，才如此发福的吧。\n"
        );
        set("gender", "男性");
        set("attitude", "peaceful");
        set("age", 44);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("max_qi", 400);
        set("max_jingli", 200);
        set("neili", 100);
        set("max_neili", 100);
        set("jiali", 10);
        set("combat_exp", 2000);
        
        set_skill("force", 12);
        set_skill("dodge", 12);
        set_skill("unarmed", 12);
        set_skill("parry", 12);
        set("inquiry", ([
        "job"       : (: ask_job :),
        ]));
        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}
void init()
{
        object me;
        ::init();
        if(interactive(me=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting",1,me);
        }       
}
string ask_job()
{       
        mapping fam;
        object ob,me;
        me=this_player();
        if (!(fam = this_player()->query("family"))
            ||fam["family_name"] != "浣花剑派")
            return RANK_D->query_respect(me)+"与本派素无来往，不知此话从何谈起？";
        if (me->query("combat_exp")>=30000)
            return RANK_D->query_respect(me)+"做这个工作太委屈你了，你还是去干别的吧！";
        if (me->query_temp("do_job1",1))
            return RANK_D->query_respect(me)+"你还在这里干什么还不去做工作。"; 
        ob = new(__DIR__"obj/liandao");
        ob->move(me);
        me->set_temp("do_job1",1);
        me->add_temp("do_num",5+random(5));
        command("nod "+me->query("id"));
        message_vision("说完$n递给了$N一把"+HIW+"镰刀。\n"NOR,me,this_object());
        return "好吧，快去西边的草地去割草。";
        
}
void greeting(object me)
{
        if( !me || environment(me) != environment() )
        return;
        if (me->query_temp("do_over_job1"))
        {
                tell_object(me,HIR"厨师对你说道：这位"+RANK_D->query_respect(me)+"，快去放草料，草不够了！\n\n"NOR);
        }
        else
        {
        command("smile "+me->query("id"));
        }
}   

