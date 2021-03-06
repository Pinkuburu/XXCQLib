// NPC: wendi.c
// Created by Zeus 1999.4.7
// Modified by Zeus 1999.5.12
// 
// 

inherit NPC;
void recover_ob();

void create()
{
        set_name("温帝", ({ "wen di"}) );
        set("gender", "男性" );
        set("age", 54);
        set("per", 15);
        set("long",
                "大字号xxxxxxxxxxxxxxxxxxx\n");
        set("qi", 2000);
        set("max_qi", 2000);
        set("jingli", 2000);
        set("max_jingli", 2000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 200);

        set("combat_exp", 1000000);

        set_skill("lphand", 140);    //施毒手法
        set_skill("force", 140);     //基本内功
        set_skill("dodge", 140);     //基本轻功
        set_skill("parry", 140);     //基本招架
        set_skill("poisonk", 140);   //毒药知识
        set_skill("duzun", 140);     //惟毒独尊
        set_skill("zhixin", 140);    //温故知新
        set_skill("qianli", 140);    //毒行千里
        set_skill("duzi-du", 140);   //毒字毒
        set_skill("literate", 100);  //读书写字

        map_skill("force", "zhixin");
        map_skill("dodge", "qianli");
        map_skill("lphand", "duzi-du");
        map_skill("parry", "duzi-du");

	prepare_skill("lphand", "duzi-du");

	create_family("老字号温家", 3, "弟子");

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "lphand.feixing" :),
		(: recover_ob :)
        }) );

        setup();

        add_money("gold", 10);

	carry_object("/d/huanhua/npc/obj/liangongfu")->wear();
}
void recover_ob()
{
        command("yun recover");
        return;
}
