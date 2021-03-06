// tangyaoshun.c
inherit NPC;
inherit F_MASTER;

int give_job();
int go_xin();
int fail_xin();
int succeed_xin();

void create()
{
	set_name("唐尧舜", ({ "tang", "yaoshun"}));
//	set("nickname", "小师妹");
	set("long", 
"唐尧舜XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX。\n");
	set("gender", "男性");
	set("age", 55);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 18);
	set("int", 25);
	set("con", 24);
	set("dex", 28);

	set("max_qi", 1500);
	set("max_jingli", 1000);
	set("max_douzhi", 1200);
	set("douzhi", 1200);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 40);
	set("combat_exp", 1000000);
	set("score", 7000);

	set_skill("force", 200);

	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("sword", 200);
	set_skill("blade", 200);
	set_skill("strike", 200);
/*	set_skill("zixia-shengong", 30);
	set_skill("hunyuan-zhang", 50);
	set_skill("huashan-jianfa", 50);
	set_skill("huashan-shenfa", 50);
	set_skill("fanliangyi-dao", 30);

	map_skill("force", "zixia-shengong");
	map_skill("blade", "fanliangyi-dao");
	map_skill("dodge", "huashan-shenfa");
	map_skill("parry", "huashan-jianfa");
	map_skill("sword", "huashan-jianfa");
	map_skill("strike", "hunyuan-zhang");

	prepare_skill("strike", "hunyuan-zhang");
	prepare_skill("cuff", "poyu-quan");
*/
	create_family("四川唐门", 15, "弟子");

	set("inquiry", ([
		"job" : ( : give_job  : ),
	]));

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangjian")->wield();
}

void init()
{
	call_out("check", 1);
}

int give_job()
{
	object me;
	string msg;
	int whose;

	me = this_player();

	if ( (string)me->query("family/family_name") != "四川唐门" )
	{
		command("say “你是什么人，为什么会在这里！”\n");
        	return 1;
	}

	if( !environment() || base_name(environment()) != query("startroom") )
	{
		say("唐尧舜说道:“我现在没心情给你派活，等我回莲云阁再说吧！”\n");
		return 0;
	}

	if ( (int)me->query_temp("tangmen/yao") || (int)me->query_temp("tangmen/biao") || (int)me->query_temp("tangmen/duyao") || (int)me->query_temp("tangmen/xin"))
		command("say “你已经有任务在身了，还要什么任务？”\n");
	else
	{
		if ( me->query("combat_exp") <= 20000 )
		{
			command("say “恩...好象制药房正缺人手！你去问问吧！”\n");
			me->set_temp("tangmen/yao",1);
		}
		else
			if ( me->query("combat_exp") <= 50000 )
			{
				command("say “恩...好象制镖房正缺人手！你去问问吧！”\n");
				me->set_temp("tangmen/biao",1);
			}
			else
				if ( me->query("combat_exp") <= 100000 )
				{
					command("say “恩...好象制毒房正缺人手！你去问问吧！”\n");
					me->set_temp("tangmen/du",1);
				}
				else
					if ( me->query("combat_exp") <= 200000 )
						if ( me->query("tangmen/succeedxin") && me->query_temp("tangmen/succeedxin"))
							command("say “你刚刚回来，还是先休息休息再说吧！”");
						else
							if ( me->query("tangmen/succeedxin") && !me->query_temp("tangmen/succeedxin"))
							{
								command("say “你刚刚回来，还是先休息休息再说吧！”");
								remove_call_out("go_xin");
								remove_call_out("succeed_xin");
								me->set_temp("tangmen/succeedxin", 1);
								call_out("succeed_xin", 300);
							}
							else
								if ( me->query("tangmen/failxin") && me->query_temp("tangmen/failxin") )
									command("say “你这个废物，还是先练好功夫再说吧！别给唐家丢脸了。”");
								else
									if ( me->query("tangmen/failxin") && !me->query_temp("tangmen/failxin") )
									{
										command("say “你这个废物，还是先练好功夫再说吧！别给唐家丢脸了。”");
										me->set_temp("tangmen/failxin", 1);
										remove_call_out("go_xin");
										remove_call_out("fail_xin");
										call_out("fail_xin", 900);
									}
									else
									{
										command("say “恩...我这里有一封信你给我送到霹雳堂温家去吧！”");
										command("say “一定要在一天内回来！”\n");
										me->set_temp("tangmen/xin",1);
										me->set("tangmen/xin",1);
										call_out("go_xin", 900);
									}
					else
					{
						command("say “你已经有一些武功根基了，可以去外面磨练磨练了！”\n");
					}
	}
	return 1;
}

void attempt_apprentice(object ob)
{
    if ((int)ob->query("shen") >100 || (int)ob->query ("shen") < -100 || (int)ob->query ("combat_exp") > 1000 )
	{
        	command("say “我四川唐门乃是武林世家，你已是武林中人，我不能收你为徒！”\n");
                return;
        }

    command("say “好吧，从今天起你就是唐门的弟子了。”\n");
    command("recruit " + ob->query("id"));
}

void check()
{
	object me;
	me = this_player();
	if ( me->query("tangmen/xin") )
		if ( me->query_temp("tangmen/xin") == 2 )
		{
			command("say “信送到了？很好，你下去休息吧！”\n");
			me->delete("tangmen/xin");
			me->delete_temp("tangmen/xin");
			me->set("tangmen/ succeedxin", 1);
			me->set_temp("tangmen/succeedxin", 1);
			remove_call_out("go_xin");
			call_out("succeed_xin", 300);
			me->add("combat_exp", 800 + random(200));
			me->add("potential", 100 + random(50));
		}
		else
			if ( me->query_temp("tangmen/xin") == 1 )
				command("say “怎么还不去送信，这是急事，马上去办！”\n");
			else
				if ( !me->query_temp("tangmen/xin") )
				{
					command("say “你这个废物，连这点事儿都办不了！”\n");
					me->delete("tangmen/xin");
					me->set("tangmen/failxin", 1);
					me->set_temp("tangmen/failxin", 1);
					remove_call_out("go_xin");
					call_out("fail_xin", 900);
				}
	return;
}
int go_xin()
{
	this_player()->delete_temp("tangmen/xin");
}
int fail_xin()
{
	this_player()->delete("tangmen/failxin");
	this_player()->delete_temp("tangmen/failxin");
}
int succeed_xin()
{
	this_player()->delete("tangmen/succeedxin");
	this_player()->delete_temp("tangmen/succeedxin");
}