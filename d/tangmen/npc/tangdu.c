// tangdu

inherit NPC;

int give_job();
int give_duyao();

void create()
{
	set_name("唐毒", ({ "tang du", "tang", "du"}));
//	set("nickname", "小师妹");
	set("long", 
"唐毒xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx。\n");
	set("gender", "男性");
	set("age", 55);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 18);
	set("int", 25);
	set("con", 24);
	set("dex", 28);

	set("max_qi", 600);
	set("max_jingli", 500);
	set("max_douzhi", 600);
	set("douzhi", 600);
	set("neili", 600);
	set("max_neili", 500);
	set("jiali", 10);
	set("combat_exp", 30000);
	set("score", 5000);

	set_skill("force", 30);
	set_skill("dodge", 60);
	set_skill("parry", 40);
	set_skill("sword", 50);
	set_skill("blade", 40);
	set_skill("strike", 50);
/*
	set_skill("zixia-shengong", 30);
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
	create_family("四川唐门", 2, "弟子");

	set("inquiry", ([
		"job" : ( : give_job  : ),
		"工作": ( : give_job  : ),
		"duyao": ( : give_duyao : ),
		"毒药": ( : give_duyao : ),
	]));

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangjian")->wield();
}

int give_job()
{
	object me, du;
	string msg, targ;
	int coun;

	string *tar = ({
		"","蜈蚣","毒蝎子","竹叶青","金环蛇","蝮蛇","千年毒王",
//		"蝎毒","蝎子壳","蝎子尾","蝮蛇毒","蝮蛇胆","蝮蛇皮","青蛇毒","青蛇胆","青蛇皮","金蛇毒","金蛇胆","金蛇皮",
	});

	me = this_player();
	du = this_object();

	if( !environment() || base_name(environment()) != query("startroom") )
	{
		say("唐毒说道:“我现在没心情给你派活，等我回制毒房再说吧！”\n");
		return 0;
	}

	if ( !(int)me->query_temp("tangmen/du") )
		command("say “这里没有活能给你干，你听谁说的？”");
	else
	{
		if ( (int)me->query_temp("duyao") )
		{
	                command("say “你还没有完成刚才给你的任务呢！”");
			return 1;
		}
		coun = 1 + random(sizeof(tar));
		if ( coun == sizeof(tar) )
			coun = ( sizeof(tar) - 1 );
		targ = tar[coun];
		printf("%d/%d\n",coun,sizeof(tar));
		say("唐毒说道:“我这里正缺一味毒物，快去给我找一只" + targ + "来吧！”\n");
		me->set_temp("duyao",coun);
	}
	return 1;
}

int give_duyao()
{

}

int accept_object(object who, object ob)
{
	command("say 要是找到了，就放到储藏室去吧！给我干什么?");
	write("唐毒冲着你扬了扬手中一只墨绿色的虫子，嘿嘿奸笑了几声。\n");
	return 0;
}