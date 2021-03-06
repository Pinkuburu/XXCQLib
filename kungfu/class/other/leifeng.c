// leifeng.c 雷锋

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("雷锋", ({ "lei feng", "lei", "feng" }));
	set("nickname", "鹰爪王");
	set("title", "鹰爪门掌门");
	set("long", 
"他有一双手，简直就似鹰爪一般，结了厚厚的茧子，\n"
"而且手上肤色，如桐油一般，加上指爪，又利又尖，\n"
"他的脸容，凸鼻三角眼，正恰似一张鹰脸。\n");
	set("gender", "男性");
	set("age", 48);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 40);
	set("int", 20);
	set("con", 30);
	set("dex", 30);
	set("bac", 30);
	
	set("qi", 1600);
	set("max_qi", 1600);
	set("jingli", 1000);
	set("max_jingli", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);

	set("combat_exp", 1000000);
	set("score", 100000);

	set_skill("claw", 150);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("jifadodge", 100);
	set_skill("parry", 150);
	set_skill("yingzhao-gong", 150);
	set_skill("jifaforce", 100);

	map_skill("force", "jifaforce");
	map_skill("claw", "yingzhao-gong");
	map_skill("parry", "yingzhao-gong");
	map_skill("dodge", "jifadodge");

	prepare_skill("claw", "yingzhao-gong");

	create_family("鹰爪门", 3, "弟子");

	set("chat_msg_combat", ({
                (: exert_function, "recover" :),
	}) );

	setup();

	carry_object("/clone/misc/cloth")->wear();
}

void attempt_apprentice(object ob)
{
	if ((int)ob->query_str() < 25) {
		command("say 依我看" + RANK_D->query_respect(ob) + "的资质似乎不适合学我鹰爪门武功？");
		return;
	}

	command("say 好吧，我就收下你了。");
	command("recruit " + ob->query("id"));

	return;
}
