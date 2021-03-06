// Npc: /kungfu/class/shaolin/xu-ming.c
// Date: YZC 96/01/19

inherit NPC;

int ask_drug1();
int ask_drug2();
int ask_drug3();

void create()
{

	set_name("铁辉", ({"tie hui","tie","hui",}));
	set("long",
		"他是一位身穿黄布袈裟的青年僧人。脸上稚气未脱，身手却已相\n"
		"当矫捷，看来似乎学过一点武功。\n"
	);

	set("gender", "男性");
	set("title", "少林寺药品库监理");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 35);
	set("dex", 20);
	set("max_qi", 450);
	set("qi", 450);
	set("max_jingli", 400);
	set("jingli", 400);
	set("neili", 300);
	set("max_neili", 300);
	set("jiali", 20);
	set("combat_exp", 15000);
	
	set_skill("force", 40);
	set_skill("banruo-changong", 40);
	set_skill("dodge", 40);
	set_skill("shaolin-shenfa", 40);
	set_skill("cuff", 50);
	set_skill("luohan-quan", 50);
	set_skill("parry", 40);

	map_skill("force", "banruo-changong");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("parry", "luohan-quan");

	prepare_skill("cuff", "luohan-quan");

	create_family("少林派", 37, "弟子");

	set("inquiry", ([
		"drug" : "我这里有一些虎骨贴、活血丹和几颗大还丹。",
		"活血丹" : (: ask_drug1 :),
		"大还丹" : (: ask_drug2 :),
		"虎骨贴" : (: ask_drug3 :),
        ]) );

	setup();

        carry_object(__DIR__"obj/huijiasha")->wear();
        carry_object(__DIR__"obj/sengxie")->wear();
}

int ask_drug1()
{
	object me, ob;
	me = this_player();

	if (me->query_condition("ask_drug") > 0)
	{
		message_vision("铁辉抱歉的说：“我这里药品有限，别的弟子也要用，我刚给过你一次，你待会再来要吧。”\n", me);
		return 1;
	}

	ob = new(__DIR__"obj/huoxue");
	ob->move(me);
	message_vision("铁辉给了$N一颗活血丹，然后叮嘱道：活血丹虽非神药，但也来之不易，千万不要浪费。\n\n", me);

	me->apply_condition("ask_drug", 60);

	return 1;
}

int ask_drug2()
{
	object me, ob, drug;
	me = this_player();
	ob = this_object();

	if (ob->query("no_drug"))
		return notify_fail("铁辉抱歉的说：“我这里暂时没有大还丹了，你待会再来吧。\n”");

	if (me->query_condition("ask_drug") > 0)
	{
		message_vision("铁辉抱歉的说：“我这里药品有限，别的弟子也要用，我刚给过你一次，你待会再来要吧。”\n", me);
		return 1;
	}

	drug = new(__DIR__"obj/dahuan-dan");
	drug->move(me);
	message_vision("铁辉给了$N一颗大还丹，然后叮嘱道：大还丹配之极难，服之有奇效，千万不要浪费。\n\n", me);

	me->apply_condition("ask_drug", 120);

	ob->set("no_drug", 1);
	call_out("recover", 3600, ob);

	return 1;
}

int ask_drug3()
{
	object me, ob;
	me = this_player();

	if (me->query_condition("ask_drug") > 0)
	{
		message_vision("铁辉抱歉的说：“我这里药品有限，别的弟子也要用，我刚给过你一次，你待会再来要吧。”\n", me);
		return 1;
	}

	ob = new(__DIR__"obj/hugutie");
	ob->move(me);
	message_vision("铁辉给了$N一贴虎骨贴，然后叮嘱道：虎骨贴配之不易，千万不要浪费。\n\n", me);

	me->apply_condition("ask_drug", 60);

	return 1;
}

void recover(object ob)
{
	ob->delete("no_drug");
	return;
}