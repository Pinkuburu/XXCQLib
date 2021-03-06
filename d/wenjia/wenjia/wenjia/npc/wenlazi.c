// NPC: wenlazi.c
// Created by Zeus 1999.4.7
// Modified by Zeus 1999.4.7
// 
// 

inherit NPC;
void recover_ob();

void create()
{
        set_name("温辣子", ({ "wen","wen lazi", "lazi"}) );
        set("gender", "男性" );
        set("age", 50);
        set("per", 10);
        set("long",
                "这个人是老字号中死字号的副首脑，他沉默寡言，\n"+
                "面色阴沉，双手一直藏在袖子里。\n");
        set("attitude", "friendly");

        set("qi", 2000);
        set("max_qi", 2000);
        set("jingli", 2000);
        set("max_jingli", 2000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 100);

        set("combat_exp", 1000000);

        set_skill("lphand", 150);    //施毒手法
        set_skill("force", 150);     //基本内功
        set_skill("dodge", 150);     //基本轻功
        set_skill("parry", 150);     //基本招架
        set_skill("duzun", 150);     //惟毒独尊
        set_skill("zhixin", 150);    //温故知新
        set_skill("qianli", 150);    //毒行千里
        set_skill("poisonk", 150);   //毒药知识
        set_skill("shengdu", 150);   //声毒
        set_skill("literate", 130);  //读书写字

        map_skill("force", "zhixin");
        map_skill("dodge", "qianli");
        map_skill("lphand", "shengdu");
        map_skill("parry", "shengdu");

	prepare_skill("lphand", "shengdu");

	create_family("老字号温家", 3, "弟子");

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "lphand.wusheng" :),
		(: recover_ob :)
        }) );

        setup();

        add_money("gold", 5);

	carry_object("/d/huanhua/npc/obj/liangongfu")->wear();
}
void recover_ob()
{
        command("yun recover");
        return;
}
