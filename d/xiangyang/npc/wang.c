// huoji. 药铺伙计

inherit NPC;
#include <ansi.h>

void create()
{
    set_name("王小二", ({ "wang", "wang xiaoer", "xiaoer"}));
	set("str", 20);
	set("gender", "男性");
	set("age", 27);
	set("long", "他是一个非常健壮的年轻人，但似乎不会功夫。\n");
	set("max_qi",350);
	set("eff_qi",350);
	set("qi",350);
	set("combat_exp", 2000);
	set("attitude", "friendly");

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

#include "/d/quanli/npc/die_quest.c"
