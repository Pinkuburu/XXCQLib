// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("木人", ({ "mu ren","mu","ren" }));
	set("gender", "男性");
	set("age", 26);
	set("long", 
		"一个做工精巧的木人。\n");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 15);
	set("con", 20);
	set("dex", 25);
	set("bac", 15);

	set("qi", 300);
	set("max_qi", 300);
	set("jingli", 200);
	set("max_jingli", 200);
	set("neili", 100);
	set("max_neili", 100);
	
	set("combat_exp", 100);
	
	set_skill("force", 1);
	set_skill("dodge", 1); 
	set_skill("club", 1); 
	set_skill("parry", 1); 
	set_skill("confu", 1); 
	
	setup();

	carry_object("/clone/misc/cloth")->wear();
	carry_object(__DIR__"obj/mubi")->wield();
}