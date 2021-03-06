// ding.c 家丁

inherit NPC;
#include <ansi.h>

int ask_baishi();

void create()
{
	set_name("虎组组员", ({ "jia ding", "ding" }));
	set("age", 25);
	set("gender", "男性");
	set("long", "他是一个精壮的青年男子，每日里就负责在门口戒备及接待来客。\n");
	set("attitude", "peaceful");

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 10000);
	set("shen_type", 1);

	set_skill("force", 30);
	set_skill("jiuqu-xinfa", 30); 
	set_skill("strike", 30);
	set_skill("feixu-zhang", 30);
	set_skill("dodge", 30); 
	set_skill("huanhua-shenfa", 30); 
	set_skill("sword", 30); 
	set_skill("parry", 30); 
	set_skill("literate", 30); 
	set_skill("confu", 30); 
	set_skill("huanhua-jian", 30); 

	map_skill("force", "jiuqu-xinfa");
	map_skill("dodge", "huanhua-shenfa");
	map_skill("strike", "feixu-zhang");
	map_skill("parry", "huanhua-jian");
	map_skill("sword", "huanhua-jian");

	prepare_skill("strike", "feixu-zhang");
	
	create_family("浣花剑派", 6, "弟子");

	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object(__DIR__"obj/liangongfu")->wear();
}