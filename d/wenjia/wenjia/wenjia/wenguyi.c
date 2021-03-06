// NPC: wenguyi.c 温故衣
// Created by Zeus 1999.7.1
// Modified by Zeus 1999.7.1
// 
// 温家的终极师父

inherit F_MASTER;
inherit F_DEALER;

#include <ansi.h>

void init();
void recover_ob();
int give_task(string);

void create()
{
        set_name("温故衣", ({ "wen guyi" , "wen"}) );
        set("gender", "男性" );
        set("age", 38);
        set("per", 20);
        set("long",
                "这位文质彬彬的中年人一团和气,他就是老字号里专管藏毒的大字号的负责人。\n");
        set("attitude", "friendly");

        set("qi", 5000);
        set("max_qi", 5000);
        set("jingli", 5000);
        set("max_jingli", 5000);
        set("neili", 15000);
        set("max_neili", 15000);
        set("jiali", 200);

        set("combat_exp", 10000000);

        set_skill("lphand", 250);    //施毒手法
        set_skill("force", 250);     //基本内功
        set_skill("dodge", 250);     //基本轻功
        set_skill("parry", 250);     //基本招架
        set_skill("poisonk", 250);   //毒药知识
        set_skill("duzun", 300);     //惟毒独尊
        set_skill("zhixin", 250);    //温故知新
        set_skill("qianli", 250);    //毒行千里
        set_skill("duzi-du", 250);   //毒字毒
        set_skill("shengdu", 250);   //声毒
        set_skill("bupangguan", 250);//袖手不旁观
        set_skill("literate", 250);  //读书写字

        map_skill("force", "zhixin");
        map_skill("dodge", "qianli");
        map_skill("lphand", "duzun");
        map_skill("parry", "duzun");

        prepare_skill("lphand", "duzun");

        create_family("老字号温家", 2, "弟子");

        setup();

        add_money("gold", 10);

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "lphand.weiwo" :),
                (: recover_ob :)
        }) );

	carry_object(__DIR__"obj/chouduan")->wear();
}

void attempt_apprentice(object me)
{
        me = this_player();

        if (((me->query("combat_exp"))>30000) && (!(string)me->query("family/family_name") 
             || (string)me->query("family/family_name") != "老字号温家") ) {
                command("say " + RANK_D->query_respect(me)+"既然有名师指导，又何必来我温家。");
                return;
        }
        if ( me->query("shen") < 0) {
                command("say 我们温家虽然在武林中算不上名门正派，温家弟子都是不能为祸江湖的。");
                command("say 在德行方面，" + RANK_D->query_respect(me) +
                        "是否还做得不够？");
                return;
        }
        if ( me->query_skill("lphand", 1) < 150) {
                command("say 我们老字号温家是使毒的，施毒手法对我们来说就如生命一样重要。"); 
                command("say " + RANK_D->query_respect(me) + 
                        "是否还应该在施毒手法上多下点功夫？");
                return;
        }
        if ( me->query_skill("zhixin", 1) < 150) {
                command("say 我们老字号温家虽然是使毒的，但使毒时需要内功把毒药放出去。"); 
                command("say " + RANK_D->query_respect(me) + 
                        "是否还应该在内功心法上多下点功夫？");
                return;
        }

        if ( (string)me->query("family/master_id") != "wen wen" ) {
                command("angry " + me->query("id"));
                command("say 你要先拜了其他的温家高手才能来拜我。"); 
                command("grin " + me->query("id"));
                command("say 想学温家绝技「惟我毒尊」没有怎么容易。"); 
                return;
        }

        command("say 好吧，我就收下你了。");
        command("recruit " + me->query("id"));
        command("chat* nod");
        command("chat 我们温家又多了一个像"+me->query("id")+"一样的高手了。");
}

void recover_ob()
{
        command("yun recover");
        return;
}
