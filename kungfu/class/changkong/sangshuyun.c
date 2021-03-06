// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
	set_name("桑书云", ({"sang shuyun", "sang", "shuyun"}));
	set("title", "长空帮帮主");
	set("nickname", "长空神指");
	set("gender", "男性");
	set("age", 45);
	set("long", 
		"待写......\n");
	set("attitude", "peaceful");
	set("str", 35);
	set("int", 35);
	set("con", 35);
	set("dex", 35);

	set("qi", 1500);
	set("max_qi", 1500);
	set("jing", 100);
	set("max_jing", 100);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);
	
	set("combat_exp", 1200000);
	set("score", 20000);
	
	set_skill("force", 150);
	set_skill("tianyu-xinfa", 150); 
	set_skill("finger", 150);
	set_skill("changkong-zhi", 200); 
	set_skill("dodge", 150); 
	set_skill("tianyu-shenfa", 150); 
	set_skill("tianyu-qijian", 200); 
	set_skill("sword", 150); 
	set_skill("parry", 150); 
	
	map_skill("force", "tianyu-xinfa");
	map_skill("finger", "changkong-zhi");
	map_skill("sword", "tianyu-qijian");
	map_skill("dodge", "tianyu-shenfa");
	
	prepare_skill("finger", "changkong-zhi");

	create_family("长空帮", 1, "帮主");

	setup();

	carry_object("/clone/armor/changpao")->wear();
	carry_object("/clone/weapon/changjian")->wield();

}

void attempt_apprentice(object ob)
{
	command("say 好吧，希望" + RANK_D->query_respect(ob) +
	"能好好学习本门武功，将来在江湖中闯出一番作为。");
	command("recruit " + ob->query("id"));
	ob->set("title", "长空帮普通帮众");
	return;
}
