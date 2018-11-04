// NPC: wenxinlaoxie.c
// Created by Zeus 1999.4.7
// Modified by Zeus 1999.4.7
// 
// 

inherit NPC;

void create()
{
        set_name("温心老契", ({ "wenxin laoxie", "laoxie"}) );
        set("gender", "男性" );
        set("age", 55);
        set("per", 5);
        set("long",
                "这个人的长相十分奇怪,他的头就象一只凤梨,但他却是老字号\n"+
                "中的分号之一小字号的老大,得罪他,你准没好果子吃。\n");
        set("attitude", "friendly");

        set("qi", 1000);
        set("max_qi", 1000);
        set("jingli", 1000);
        set("max_jingli", 1000);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 50);

        set("combat_exp", 80000);

        set_skill("hand", 100);
        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("literate", 60);

        add_money("silver", 10);

        setup();
}
