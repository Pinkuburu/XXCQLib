// NPC: wenxiaoming.c
// Created by Zeus 1999.3.28
// Modified by Zeus 1999.3.28
// 
// 

inherit NPC;

void create()
{
        set_name("温小明", ({ "wen xiaoming"}) );
        set("gender", "男性" );
        set("age", 10+random(4));
        set("long",
                "温小男一个活泼可爱的小男孩，他在学堂里读书。\n");
        set("combat_exp", 100);
        set("attitude", "friendly");

        set("qi", 100);
        set("max_qi", 100);
        set("jingli", 150);
        set("max_jingli", 150);

        set_skill("literate", 30);

        setup();
}

