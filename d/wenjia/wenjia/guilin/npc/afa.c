// NPC: afa.c
// Created by Zeus 1999.6.5
// Modified by Zeus 1999.6.5
// 
// 
#include <ansi.h>

inherit F_DEALER;

void create()
{
        set_name("阿发", ({ "a fa"}) );
        set("title","小吃店老板");
        set("nickname",HIC"桂林第一厨"NOR);
        set("gender", "男性" );
        set("age", 26);
        set("long",
                "眼睛小小的汉族男子，眼睛里闪烁着异样的光，十分精明的样子。\n");
        set("attitude", "friendly");

	set("str", 22);
	set("int", 20);
	set("dex", 18);
	set("con", 25);

        set("qi", 500);
        set("max_qi", 500);
        set("jingli", 600);
        set("max_jingli", 600);

        set_temp("apply/attack", 15);
        set_temp("apply/defense", 20);
        set_temp("apply/damage", 10);
        set_temp("apply/armor", 15);

        set("combat_exp", 35000);

	set("vendor_goods", ({
		__DIR__"obj/hongkou",
		__DIR__"obj/baiguo",
		__DIR__"obj/mifen",
		__DIR__"obj/jiqiu",
		__DIR__"obj/facai",
		__DIR__"obj/shuiyu",
	}));

        setup();

        add_money("silver", 10);
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
