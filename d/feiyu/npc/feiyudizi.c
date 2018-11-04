// NPC: feiyudizi.c
// Created by Zeus 1999.3.27
// Modified by Zeus 1999.5.12
// 
// 

inherit NPC;

void create()
{
        set_name("飞鱼弟子", ({ "dizi"}) );
        set("gender", "男性" );
        set("age", 20+random(10));
        set("long",
                "这是一位飞鱼塘弟子。在这里到处可以看见这种服色的人。\n");
        set("attitude", "friendly");

        set("qi", 500);
        set("max_qi", 500);
        set("jingli", 400);
        set("max_jingli", 400);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 10);

        set("combat_exp", 50000);

        set_skill("unarmed", 50);     //搏击格斗
        set_skill("force", 50);       //基本内功
        set_skill("dodge", 50);       //基本轻功
        set_skill("parry", 50);       //基本招架
        set_skill("literate", 30);    //读书写字
 	    set_skill("youyu-quan",90);  //游鱼拳
         create_family("飞鱼塘", 6, "弟子");

        setup();
}
