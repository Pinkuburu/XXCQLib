// huoji. 药铺伙计

inherit NPC;
#include <ansi.h>

void create()
{
	set_name("黑老汉", ({ "hei laohan", "hei", "laohan"}));
	set("str", 20);
	set("gender", "男性");
	set("age", 45);
	set("long", "他是一个皮肤袖黑的老汉，看上去满面风霜。\n");
	set("max_qi",300);
	set("eff_qi",300);
	set("qi",300);
	set("combat_exp", 1000);
	set("attitude", "friendly");

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

#include "die_quest.c"
