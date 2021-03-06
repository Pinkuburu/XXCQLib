//Npc 祝幽
//by godzilla 11.18.99

#include <ansi.h>

string ask_job();
int ask_gongxian();
inherit F_MASTER;

inherit NPC;

void create()
{
        set_name("祝幽",({"zhu you","you","zhu"}));
        set("long","他就是天羽门下，号称为「江山一剑」的祝幽，\n");
        set("title",HIW"天羽派"NOR);
        set("nickname",HIR"江山一剑"NOR);
        set("age", 35);
        set("attitude", "friendly");
        set("shen_type", 0);
        set("str", 30);
        set("int", 35);
        set("con", 30);
        set("dex", 30);
        
        set("max_qi", 3500);
        set("max_jing", 3000);
        set("neili", 3500);
        set("max_neili", 3500);
        set("jiali", 100);
        set("combat_exp", 500000);
       
        set_skill("finger",150);
        set_skill("tianyu-zhenfa",80);
        set_skill("dodge",150);
        set_skill("force", 150);
        set_skill("parry", 150);
        set_skill("sword", 150);
        set_skill("literate", 150);
        set_skill("tianyu-qigong",150);
        set_skill("tao",150);
        set_skill("tianyu-qijian",110);
        set_skill("tianyu-bufa",150);
        
        map_skill("sword", "tianyu-qijian");
        map_skill("force", "tianyu-qigong");
        map_skill("dodge", "tianyu-bufa");
        map_skill("parry", "tianyu-qijian");
        set("inquiry", ([
        "job"       : (: ask_job :),
        "贡献"      : (: ask_gongxian :),   
        ]));
        create_family("天羽派", 7, "弟子");
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object(__DIR__"obj/cloth2")->wear();
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
        mapping quest;
        object ob,me;
        me=this_player();
        quest="/d/tianyu/quest/quest2"->query_quest();
/*
        if (me->query("family/family_name")!="天羽派")
            return RANK_D->query_respect(me)+"与本派素无来往，不知此话从何谈起？";
*/
        if (me->query("combat_exp")<40000)
            return RANK_D->query_respect(me)+"做这个工作太危险，你还是去干别的吧！";
        if (me->query_temp("do_job2",1))
            return RANK_D->query_respect(me)+"还在这里干什么?快去送密函。\n"; 
        if ( (int)me->query_condition("do_songxin" ) > 0 )
            return RANK_D->query_respect(me)+"现在还没有密函要你去送，歇息再来吧！\n";                   
        ob = new(__DIR__"obj/mihan");
        ob->move(me);
        me->set_temp("do_job2",1);
        me->apply_condition("do_songxin", 10+random(5));
        ob->set("where",quest["where_place"]);
        ob->set("human",quest["name"]);
        command("say 这里有一封送给"+quest["party"]+quest["name"]+"的密函。\n");
        command("say 事关重大，一路上一定要格外小心，不要丢失密函。\n");
        message_vision("说完$n递给了$N一封"+RED+"密函。\n"NOR,me,this_object());
        return "好，尽快上路吧。";
               
}
int ask_gongxian()
{
        object me = this_player();
         if(!me->query("gongxun"))
        {
                 return 1;
        }
        else
        {
                  command("say "+me->name()+"为本派做了"YEL+chinese_number((int)me->query("gongxun"))+CYN"次贡献,希望你继续努力。\n");   
                  return 1;
        }
} 
void greeting(object me)
{
        if( !me || environment(me) != environment() )
        return 0;
        command("smile "+me->query("id"));
}
void attempt_apprentice(object ob)
{
        
        if(ob->query("family/master_name")=="萧河")
        {
                command("say 既然你是已经是萧河的弟子，何必又到我这儿呢?\n");
                return;
        }
        if(ob->query("int")<25)
        {
                command("say 你悟性太差，不会在天羽派有多大作为的。\n");
                return;
        }
        command("nod "+ob->query("id"));
        command("say 天羽派需要你们来发扬光大。");      
        command("recruit " + ob->query("id"));
         ob->set("class","tianyumen");
}       
 

