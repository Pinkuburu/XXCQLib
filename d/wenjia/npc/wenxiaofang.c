// NPC: wenxiaofang.c
// Created by Zeus 1999.3.28
// Modified by Zeus 1999.3.28
// 
// 

inherit NPC;

void create()
{
        set_name("温小芳", ({ "wen xiaofang"}) );
        set("gender", "女性" );
        set("age", 10+random(4));
        set("long",
                "温小芳一个可爱伶俐的小女孩，她在学堂里读书。\n");
        set("combat_exp", 100);
        set("attitude", "friendly");

        set("qi", 100);
        set("max_qi", 100);
        set("jingli", 200);
        set("max_jingli", 200);

        set_skill("literate", 30);

        setup();
}

