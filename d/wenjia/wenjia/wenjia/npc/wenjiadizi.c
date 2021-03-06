// NPC: wendabao.c
// Created by Zeus 1999.3.27
// Modified by Zeus 1999.7.21
// 
// 

inherit NPC;

void create()
{
        set_name("温家弟子", ({ "dizi"}) );
        set("gender", "男性" );
        set("age", 20+random(10));
        set("long",
                "这是一位温家弟子。在温家总堂里到处可以看见这种服色的人。\n");
        set("attitude", "friendly");

        set("qi", 500);
        set("max_qi", 500);
        set("jingli", 400);
        set("max_jingli", 400);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 10);

        set("combat_exp", 30000);

        set_skill("lphand", 50);    //施毒手法
        set_skill("force", 50);     //基本内功
        set_skill("dodge", 50);     //基本轻功
        set_skill("parry", 50);     //基本招架
        set_skill("bupangguan", 50);//袖手不旁观
        set_skill("zhixin", 50);    //温故知新
        set_skill("qianli", 50);    //毒行千里
        set_skill("literate", 30);  //读书写字

        map_skill("force", "zhixin");
        map_skill("dodge", "qianli");
        map_skill("lphand", "duzun");
        map_skill("parry", "duzun");

	prepare_skill("lphand", "duzun");

	create_family("老字号温家", 6, "弟子");

        setup();
}
