// Npc: /kungfu/class/shaolin/qing-guan.c
// Date: YZC 96/01/19

#include <ansi.h>
inherit NPC;

int ask_job();

void create()
{
	set_name("天象", ({	"tian xiang", "tian", "xiang",}));
	set("long",
		"他是一位体格强健的壮年僧人，他身得虎背熊腰，全身似乎蕴含\n"
		"着无穷劲力。他身穿一袭白布黑边袈裟，似乎身怀武艺。\n"
	);
	set("title", "少林寺镇山监寺");
	set("nickname", "雷霆二僧");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 30);
	set("shen_type", 1);
	set("str", 30);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_qi", 1000);
	set("qi", 1000);
	set("max_jingli", 600);
	set("jingli", 600);
	set("neili", 700);
	set("max_neili", 700);
	set("jiali", 50);
	set("combat_exp", 150000);
	set("score", 100);

	set_skill("force", 90);
	set_skill("banruo-changong", 90);
	set_skill("dodge", 90);
	set_skill("shaolin-shenfa", 90);
	set_skill("strike", 100);
	set_skill("banruo-zhang", 100);
	set_skill("parry", 100);
	set_skill("buddha", 80);
	set_skill("literate", 80);

	map_skill("force", "banruo-changong");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("strike", "banruo-zhang");
	map_skill("parry", "banruo-zhang");

	prepare_skill("strike", "banruo-zhang");

	create_family("少林派", 36, "弟子");

        set("inquiry", ([
                "job" : (: ask_job :),
        ]) );

	setup();

        carry_object(__DIR__"obj/heijiasha")->wear();
        carry_object(__DIR__"obj/sengxie")->wear();
}

int ask_job()
{
	object ob, me;
	mapping myfam, quest;

	me = this_player();
	ob = this_object();
	myfam = (mapping)me->query("family");
	quest = "/d/shaolin/quest/txquest"->query_quest();

	if (me->query_temp("where") == "fail")
	{
		command("sigh");
		command("disapp " + me->query("id"));
		command("say 你先下去吧，这段时间不用来轮班职守了。");
		me->delete_temp("where");
		return 1;
	}

	if (me->query_condition("txjob_fail") > 0)
	{
		command("say 现在不需要你去职守,你还是趁这段时间多练练功吧。");
		return 1;
	}

        if(me->query("qi") < me->query("max_qi")/2 || me->query("jingli") < me->query("max_jingli")/2)
        {
          command("say 你的精力和气血已经不够了,去休息休息吧!\n");
          return 1;
        }
        if(me->query("combat_exp")<10000)
        {
          command("say 你的武功太低了,不能胜任这个任务!\n");
         return 1;
        }
        if(me->query("combat_exp")>300000)
        {
          command("say 你不用去做这些小事了,去练功吧!\n");
          return 1;
        }
	if (me->query_temp("where") == "over")
	{
		command("say 好好，干的好，你下去歇歇吧。");
		me->add("potential", 50+random(50));
		me->add("combat_exp", 100+random(100));
		me->delete_temp("where");
		return 1;
	}

	if (me->query_temp("where"))
	{
		command("say 让你去职守，你怎么又回来了？还不快回去！");
		return 1;
	}

	if (myfam["family_name"] != "少林派")
	{
		command("say 施主，真是不敢当，阿弥陀佛！");
		return 1;
	}

	command("say 你来的正好，最近经常有外人擅闯" + quest["quest"] + "，意欲" + quest["quest_object"] + "，守寺人手有些不足。");
	command("say 你现在马上去" + quest["quest_place"] + "职守一班岗，千万不能让坏人溜过去。");
	command("say 职守期间绝对不可删离，否则后果不堪设想。");

	me->set_temp("where", quest["file_name"]);

	call_out("check_guard", 60, me);

	return 1;
}

void check_guard(object me)
{
	object where;

	where = environment(me);

	if (file_name(where)==me->query_temp("where"))
	{
          message_vision(HIC"$N抖擞精神，守住要道，值班站岗。\n"NOR, me);
          message_vision(HIC"$N的任务成功完成,回去再要工作吧。\n"NOR, me);
		//me->apply_condition("txquest", 20);
	       me->set_temp("where","over");
           me -> receive_damage ("jingli", me->query("jingli")/4);
           me -> receive_damage ("qi", me->query("qi")/4);
	}
	else
	{
		message_vision("\n突然旁边闪出了一个僧兵，严肃的对$N说：让你去职守，你却迟迟不到岗，等我去报告天龙师兄。\n", me);
		message_vision("话一说完，僧兵就急急忙忙向精进场的方向离开了。\n\n", me);
		me->set_temp("where", "fail");
		me->apply_condition("txjob_fail",50);
	}
	return;
}
