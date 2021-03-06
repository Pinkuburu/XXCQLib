// NPC: wenyuehong.c
// Created by Zeus 1999.4.7
// Modified by Zeus 1999.4.7
// 
// 

inherit NPC;

void create()
{
        set_name("温约红", ({ "wen yuehong", "yuehong"}) );
        set("gender", "男性" );
        set("age", 36);
        set("per", 25);
        set("long",
                "这个人看上去醉熏熏的，一看就知他是个酒鬼，人称“三缸公子”\n"+
                "他就是老字号中的活字号的老二，他也经常被派出去执行任务。\n");
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
