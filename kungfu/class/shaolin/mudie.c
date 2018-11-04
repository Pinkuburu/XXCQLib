// Npc: /kungfu/class/shaolin/xuan-ci.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;


void create()
{
    set_name("木蝶大师", ({
        "mudie dashi",
        "mudie",
		"dashi",
	}));
	set("long",
		"他是一位白须白眉的老僧，身穿一袭金丝绣红袈裟。\n"
		"他身材略显佝偻，但却满面红光，目蕴慈笑，显得神完气足。\n"
	);


        set("title", "少林寺诵经堂首座");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1500);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 150);
	set("combat_exp", 1000000);
	set("score", 500000);
    set_skill("force", 180);
    set_skill("banruo-changong", 180);
    set_skill("blade", 180);
    set_skill("luohan-quan", 180);
    set_skill("xiuluo-dao", 180);
    set_skill("weituo-gun", 180);
    set_skill("sword", 180);
    set_skill("banruo-zhang", 180);
    set_skill("cuff", 180);
    set_skill("dodge", 180);
    set_skill("shaolin-shenfa", 180);
    set_skill("strike", 180);
    set_skill("parry", 180);
    set_skill("buddha", 180);
	set_skill("literate", 110);

    map_skill("force", "banruo-changong");
    map_skill("cuff", "luohan-quan");
	map_skill("dodge", "shaolin-shenfa");
    map_skill("blade", "xiuluo-dao");
	map_skill("hand", "fengyun-shou");

	create_family("少林派", 35, "弟子");

	setup();

        carry_object("/d/shaolin/npc/obj/jinjiasha")->wear();
        carry_object("/d/shaolin/npc/obj/sengxie")->wear();
}

void attempt_apprentice(object ob)
{
	object me; 
	mapping ob_fam, my_fam;
    string new_name,name;

	me = this_object();
	my_fam  = me->query("family");

	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "少林派")
	{
		command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "少林派") 
	{
		command("say " + RANK_D->query_respect(ob) + "是俗家弟子，不能在寺内学艺。");
		return;
	}

	if ( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "，贫僧哪里敢当 !");
		return;
	}

    if ( ob_fam["generation"] == (my_fam["generation"] + 1) && name[0..1] == "天")
	{
		command("say " + ob_fam["master_name"] + "的徒弟怎麽跑到我这儿来了，哈哈哈 !");
		command("recruit " + ob->query("id"));
	}
	else
	{
        if( ob->query("bai_mu") > 0)
        {                   command("say " + RANK_D->query_respect(ob) + "，既然你是你师傅推荐的,那我就收下你吧。\n");
                   me->delete("bai_mu");
              new_name = "天" + name[2..3];
                        ob->set("name", new_name);
                   command("say 从今以后你的法名叫做" + new_name + "，恭喜你荣升为少林派天字辈弟子 !");
        ob->delete("bai_mu");
          command("recruit " + ob->query("id"));
        }
        else         command("say " + RANK_D->query_respect(ob) + "，你辈份不合，不能越级拜师。");
		return;
	}

	return;
}

