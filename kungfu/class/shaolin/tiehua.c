// Npc: /kungfu/class/shaolin/xu-ming.c
// Date: YZC 96/01/19

#include "/kungfu/class/shaolin/other.h"
inherit NPC;

void create()
{

	set_name("铁花", ({"tie hua","tie","hua",}));
	set("long",
		"他是一位身穿灰布镶边袈裟的僧人。年纪不大却满脸的老成，出手法度森严，\n"
		"功夫很是不弱。\n"
	);

	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 27);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 35);
	set("dex", 20);
	set("bac", 23);
	set("max_qi", 800);
	set("qi", 800);
	set("max_jingli", 500);
	set("jingli", 500);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 30);
	set("combat_exp", 80000);
	
	set_skill("force", 80);
	set_skill("banruo-changong", 80);
	set_skill("dodge", 80);
	set_skill("shaolin-shenfa", 80);
	set_skill("cuff", 90);
	set_skill("luohan-quan", 90);
	set_skill("club", 90);
	set_skill("weituo-gun", 90);
	set_skill("parry", 80);
	set_skill("buddha", 80);

	map_skill("force", "banruo-changong");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("parry", "luohan-quan");
	map_skill("club", "weituo-gun");

	prepare_skill("cuff", "luohan-quan");

	create_family("少林派", 37, "弟子");

	setup();

        carry_object("/d/shaolin/npc/obj/huijiasha")->wear();
        carry_object("/d/shaolin/npc/obj/sengxie")->wear();
        carry_object("/d/shaolin/npc/obj/qimeigun")->wield();
}

void check(object me)
{
	object ob;
	mapping my_fam;

	ob = this_object();

	my_fam = me->query("family");

	if ( my_fam && my_fam["master_id"] == ob->query("id")
		&& me->query_skill("banruo-changong",1) > 60
		&& me->query_skill("buddha",1) > 60
		&& (me->query_skill("weituo-gun",1) > 60 || me->query_skill("luohan-quan",1)>60)
		&& !me->query("bai_tian")
		&& environment(me)==environment(ob))
	{
		command("pat " + me->query("id"));
		command("say 你勤奋用功，学有所成，为师能教你的已经不多了。");
		command("say 你去试着拜其他师叔伯，或者看看哪位天字辈的师祖愿意收你吧。");
		command("say 以后不要忘了为师的教诲：立百福之基，只在一念慈祥。去吧。");
		me->set("bai_tian", 1);
	}
}

void check_shou(object me)
{
	object ob;
	mapping my_fam, ob_fam;
	string name, new_name;

	ob = this_object();
	name = me->query("name");

	my_fam = me->query("family");
	ob_fam = ob->query("family");

	if ( me->query("bai_tie") && (ob_fam["generation"] + 2 == (my_fam["generation"] )) )
	{
		command("say " + me->query("name") + "，你师傅" + my_fam["master_name"] + "向我推荐过你。");
		if (me->query_skill("banruo-changong",1)<30)
		{
			command("say 我的功夫需要一定的般若禅功做根基，你学不了的。");
			command("say 你还是去拜其他的铁字辈弟子吧。");
			return;
		}
		else 
		{
			me->delete("bai_tie");
			new_name = "铜" + name[2..3];
			me->set("name", new_name);
			command("say 从今以后你的法名叫做" + new_name + "，恭喜你荣升为少林派铜字辈弟子 !");
			command("recruit " + me->query("id"));
			return;
		}
	}
	else if (ob_fam["generation"] + 1 == (my_fam["generation"] ))
	{
		if (me->query_skill("banruo-changong",1)<30)
		{
			command("say 我的功夫需要一定的般若禅功做根基，你学不了的。");
			command("say 你还是去拜其他的铁字辈弟子吧。");
			return;
		}
		command("recruit " + me->query("id"));
	}
	else
	{
		command("say " + me->query("name") + "，未得你师傅推荐，我不能收你，你回去吧。");
		return;
	}
}