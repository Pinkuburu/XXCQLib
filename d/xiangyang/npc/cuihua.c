// huoji. 药铺伙计

inherit NPC;
#include <ansi.h>

void create()
{
    set_name("翠花", ({ "cuihua", "cui", "hua"}));
	set("str", 20);
	set("gender", "女性");
	set("age", 65);
	set("long", "一个漂亮的村姑，看来非常的勤劳。\n");
	set("max_qi",300);
	set("eff_qi",300);
	set("qi",300);
	set("combat_exp", 1000);
	set("attitude", "friendly");

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

#include "/d/quanli/npc/die_quest.c"
