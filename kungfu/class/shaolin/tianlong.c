// Npc: /kungfu/class/shaolin/xuan-ci.c
// Date: YZC 96/01/19

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include "/kungfu/class/shaolin/other.h"

void create()
{
	set_name("天龙", ({"tian long","tian","long",}));
	set("long",
		"他是一位须发花白的老僧，身穿一袭金边黑布袈裟。他身材瘦高，\n"
		"太阳穴高高鼓起，似乎身怀绝世武功。\n");

	set("nickname", HIY"金刚罗汉"NOR);
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 1);
	set("str", 20);
	set("int", 18);
	set("con", 20);
	set("dex", 22);
	set("bac", 20);
	set("max_qi", 2500);
	set("eff_qi", 2500);
	set("qi", 2500);
	set("max_jingli", 2000);
	set("eff_jingli", 2000);
	set("jingli", 2000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 400000);
	set("score", 5000);

	set_skill("force", 140);
	set_skill("banruo-changong", 140);
	set_skill("dodge", 130);
	set_skill("shaolin-shenfa", 130);
	set_skill("cuff", 150);
	set_skill("luohan-quan", 150);
	set_skill("club", 150);
	set_skill("weituo-gun", 150);
	set_skill("parry", 140);
    set_skill("buddha", 124);

	map_skill("force", "banruo-changong");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("parry", "luohan-quan");
	map_skill("club", "weituo-gun");

	prepare_skill("cuff", "luohan-quan");

	create_family("少林派", 36, "弟子");

	setup();

        carry_object("/d/shaolin/npc/obj/heijiasha")->wear();
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
		&& me->query_skill("banruo-changong",1) > 120
		&& me->query_skill("buddha",1) > 120
		&& (me->query_skill("weituo-gun",1) > 120 || me->query_skill("luohan-quan",1)> 120)
		&& !me->query("bai_mu")
		&& environment(me)==environment(ob))
	{
		command("pat " + me->query("id"));
		command("say 你勤奋用功，学有所成，为师能教你的已经不多了。");
		command("say 你去试着拜其他师叔伯，或者看看哪位木字辈的师祖愿意收你吧。");
		command("say 以后不要忘了为师的教诲：纤尘不染，方解开地网天罗。去吧。");
		me->set("bai_mu", 1);
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

	if (my_fam){
	if ( me->query("bai_tian") && (ob_fam["generation"] + 2 == (my_fam["generation"] )) )
	{
		command("say " + me->query("name") + "，你师傅" + my_fam["master_name"] + "向我推荐过你。");
		if (me->query_skill("banruo-changong",1)<60)
		{
			command("say 我的功夫需要一定的般若禅功做根基，你学不了的。");
			command("say 你还是去拜其他的天字辈弟子吧。");
			return;
		}
		else 
		{
			me->delete("bai_tian");
			new_name = "铁" + name[2..3];
			me->set("name", new_name);
			command("say 从今以后你的法名叫做" + new_name + "，恭喜你荣升为少林派铁字辈弟子 !");
			command("recruit " + me->query("id"));
			return;
		}
	}
	else if (ob_fam["generation"] + 1 == (my_fam["generation"] ))
	{
		if (me->query_skill("banruo-changong",1)<60)
		{
			command("say 我的功夫需要一定的般若禅功做根基，你学不了的。");
			command("say 你还是去拜其他的天字辈弟子吧。");
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
}
