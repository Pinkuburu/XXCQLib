// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;

void heal_ob();
void recover_ob();
#include <ansi.h>

void create()
{
	set_name("孟别离", ({"meng bieli", "meng", "bieli"}));
	set("gender", "男性");
	set("nickname", HIW"恨不相逢，别离良剑"NOR);
	set("age", 30);
	set("long", 
"他这人浓眉轻蹙，脸含微优，当然是孟相逢。\n"
"与孔别离并称“刀剑二绝”的“东刀西剑”中的“西剑”。\n");
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("bac", 20);

	set("qi", 2600);
	set("max_qi", 2600);
	set("jingli", 1800);
	set("max_jingli", 1800);
	set("neili", 2100);
	set("max_neili", 2100);
	set("jiali", 50);
	
	set("combat_exp", 800000);
	set("score", 20000);
	
	set_skill("force", 140);
	set_skill("jiuqu-xinfa", 140); 
	set_skill("strike", 120);
	set_skill("feixu-zhang", 120);
	set_skill("dodge", 150); 
	set_skill("huanhua-shenfa", 150); 
	set_skill("sword", 170); 
	set_skill("parry", 150); 
	set_skill("literate", 150); 
	set_skill("confu", 120); 
	
	map_skill("force", "jiuqu-xinfa");
	map_skill("dodge", "huanhua-shenfa");
	map_skill("strike", "feixu-zhang");
	map_skill("parry", "feixu-zhang");

	prepare_skill("strike", "feixu-zhang");
	
	create_family("浣花剑派", 3, "弟子");

	setup();

	carry_object("/d/huanhua/npc/obj/jinpao")->wear();
	carry_object("/d/huanhua/npc/obj/bieli")->wield();

	set("chat_chance", 3);
	set("chat_msg", ({
		(: heal_ob :),
	}));

	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: perform_action, "strike.fenfei" :),
		(: recover_ob :)
	}) );
}

void heal_ob()
{
	command("yun heal");
	command("yun heal");
	command("yun heal");
	command("yun recover");
	return;
}

void recover_ob()
{
	command("yun recover");
	return;
}

void attempt_apprentice(object ob)
{
	command("say 我剑法未成，暂不能收徒，你过两年在来找我吧。");
	command("wave");
	return ;
}