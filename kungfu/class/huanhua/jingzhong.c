// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;

void heal_ob();
void recover_ob();
int ask_money();
#include <ansi.h>

void create()
{
	set_name("马竟终", ({"ma jingzhong", "ma", "jingzhong"}));
	set("gender", "男性");
	set("title", "浣花剑庐总管");
	set("nickname", YEL"九命总管、落地生根"NOR);
	set("age", 30);
	set("long", 
"他是一个中年汉子，身材短小，但显得颇为精干。\n"
"他就是单刀斗月狼，九死一生渡怒江，在桂林浣花剑派的马竟终。\n");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 15);
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
	
	set_skill("force", 150);
	set_skill("jiuqu-xinfa", 150); 
	set_skill("dodge", 120); 
	set_skill("huanhua-shenfa", 120); 
	set_skill("cuff", 170); 
	set_skill("tiexian-quan", 170); 
	set_skill("parry", 150); 
	set_skill("literate", 90); 
	set_skill("confu", 90); 
	
	map_skill("force", "jiuqu-xinfa");
	map_skill("dodge", "huanhua-shenfa");
	map_skill("cuff", "tiexian-quan");
	map_skill("parry", "feixu-zhang");

	prepare_skill("cuff", "tiexian-quan");
	
	create_family("浣花剑派", 3, "弟子");

	setup();

	carry_object("/d/huanhua/npc/obj/changshan")->wear();

	set("chat_chance", 3);
	set("chat_msg", ({
		(: heal_ob :),
	}));

	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: perform_action, "cuff.chong" :),
		(: recover_ob :)
	}) );

        set("inquiry", ([
                "money" : (: ask_money :),
                "工钱" : (: ask_money :),
                "gongqian" : (: ask_money :),
        ]) );
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
	object me;
	mapping my_fam, ob_fam;

	me = this_object();

	my_fam = ob->query("family");
	ob_fam = me->query("family");

	if (!(my_fam = ob->query("family")) || my_fam["family_name"] != "浣花剑派")
	{
		command("say 我是浣花剑派的人，只能指点浣花弟子的武功，真抱歉！");
		return;
	}

	if ((int)ob->query("shen") <= (-100))
	{
		command("say 你身为浣花弟子却不主张正义，甘入魔道，我浣花容不下你！");
		command("kaichu "+ob->query("id"));
		return;
	}

	if (ob->query("shen")<20000)
	{
		command("say 你维护武林正义的义举做得不够，我还不能收你。");
		command("addoil " + ob->query("id"));
		return;
	}

	if (ob->query_skill("force",1)< 90 || ob->query_skill("jiuqu-xinfa",1)<90)
	{
		command("say 我的功夫必须以扎实的内功基础为根基，你现在恐怕还学不了。");
		command("sorry " + ob->query("id"));
		return;
	}

	if (ob->query_str()<32)
	{
		command("shake " + ob->query("id"));
		command("say 我看你膂力不够，难有大成，我不想收你。");
		return;
	}

	command("say 好吧，我收下你无妨，但能否成才还要看你自己的努力。");
	command("recruit " + ob->query("id"));

	return;
}

int ask_money()
{
	object me, ob, to_ob;
	mapping myfam;
	me = this_player();
	ob = this_object();
	to_ob = present("silver_money", this_player());

	myfam = me->query("family");

	if ( !(myfam = me->query("family")) || myfam["family_name"] != "浣花剑派" )
	{
		command("hmm " + me->query("id"));
		command("say 你不是我浣花的弟子，怎么也来要工钱？");
		return 1;
	}

	else if (me->query("pay_money") - me->query("age") == 0)
	{
		command("angry " + me->query("id"));
		command("say 老想着要工钱，真没出息！");
		return 1;
	}

	else if ((me->query("succeed") < 10))
	{
		command("shake");
		command("say 就做了这么点工作就想来要工钱？不罚你就算好的了！");
		return 1;
	}

	else
	{
		command("nod");
		command("say 你等一下，我拿这一年的工钱给你，好好干呀。");
		if( !to_ob ) {
			to_ob = new("/clone/money/silver");
			to_ob->move(this_player());
			to_ob->set_amount(me->query("succeed")*2);
		} else
			to_ob->add_amount(me->query("succeed"));
		me->set("succeed", 0);
		me->set("pay_money", me->query("age"));
	        message_vision("$n给了$N几个银块和一些碎银子。\n", me, ob);
		return 1;
	}
}