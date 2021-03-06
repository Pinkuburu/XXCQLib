// NPC: wentuke.c 温家第五代弟子、初级师父  温吐克
// Created by Zeus 1999.6.9
// Modified by Zeus 1999.7.1
// 
// 原著人物!  特殊武功--毒字毒

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void recover_ob();

void create()
{
        set_name("温吐克", ({ "wen tuke","wen"}) );
        set("nickname", HIC"毒字毒"NOR );
        set("gender", "男性" );
        set("age", 30);
        set("per", 10);
        set("attitude", "friendly");

        set("qi", 1300);
        set("max_qi", 1300);
        set("jingli", 1000);
        set("max_jingli", 1000);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 100);

        set("combat_exp", 3500000);

        set_skill("lphand", 120);    //施毒手法
        set_skill("force", 120);     //基本内功
        set_skill("dodge", 120);     //基本轻功
        set_skill("parry", 120);     //基本招架
        set_skill("zhixin", 120);    //温故知新
        set_skill("poisonk", 100);   //毒药知识
        set_skill("qianli", 120);    //毒行千里
        set_skill("duzi-du", 200);   //毒字毒
        set_skill("literate", 100);  //读书写字

        map_skill("force", "zhixin");
        map_skill("dodge", "qianli");
        map_skill("lphand", "duzi-du");
        map_skill("parry", "duzi-du");

        prepare_skill("lphand", "duzi-du");

        create_family("老字号温家", 5, "弟子");

        setup();

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
		(: recover_ob :)
        }) );

        add_money("silver", 10);

        carry_object("/d/wenjia/obj/grnduanda")->wear();
}

void attempt_apprentice(object me)
{
        mapping myfam;
        me = this_player();

        myfam = (mapping)me->query("family");

        if ( me->query("combat_exp")<100000 ) {
                command("say 去江湖上多磨练磨练吧。");
                return;
        }
        if ((int)me->query("shen") < 0) {
                command("say 我们温家虽然在武林中算不上名门正派，温家弟子都是不能为祸江湖的。");
                command("say 在德行方面，" + RANK_D->query_respect(me) +
                        "是否还做得不够？");
                return;
        }
        if ((int)me->query_skill("lphand", 1) < 50) {
                command("say 我们老字号温家是使毒的，施毒手法对我们来说就如生命一样重要。"); 
                command("say " + RANK_D->query_respect(me) + 
                        "是否还应该在施毒手法上多下点功夫？");
                return;
        }
        if ((int)me->query_skill("zhixin", 1) < 50) {
                command("say 我们老字号温家虽然是使毒的，但使毒时需要内功把毒药放出去。"); 
                command("say " + RANK_D->query_respect(me) + 
                        "是否还应该在内功心法上多下点功夫？");
                return;
        }

        command("say 好吧，我就收下你了。");
        command("say 好好的学吧!");
        command("recruit " + me->query("id"));
}

void recover_ob()
{
        command("yun recover");
        return;
}
