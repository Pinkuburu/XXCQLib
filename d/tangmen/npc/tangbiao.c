// tangbiao

inherit NPC;

int give_job();
int give_anqi();

void create()
{
	set_name("唐镖", ({ "tang biao", "tang", "biao"}));
//	set("nickname", "小师妹");
	set("long", 
"唐方身材娇小，长的极为清秀，又带几分英气，清劲多于柔弱。\n"
"她是唐门长房宗主唐尧舜之女，后又得唐老太太亲授衣钵，在唐门地位颇高。\n");
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
//	set_skill("zixia-shengong", 30);
	set_skill("dodge", 60);
	set_skill("parry", 40);
	set_skill("sword", 50);
	set_skill("blade", 40);
	set_skill("strike", 50);
/*	set_skill("hunyuan-zhang", 50);
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
		"anqi": ( : give_anqi : ),
		"暗器": ( : give_anqi : ),
	]));

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangjian")->wield();
}

int give_job()
{
	object me, biao;
	string msg, targ;
	int coun;

	string *tar = ({
		"","铁矿石",
	});

	me = this_player();
	biao = this_object();

	if( !environment() || base_name(environment()) != query("startroom") )
	{
		say("唐镖说道:“我现在没心情给你派活，等我回制镖房再说吧！”\n");
		return 0;
	}

	if ( !(int)me->query_temp("tangmen/biao") )
		command("say “这里没有活能给你干，你听谁说的？”");
	else
	{
		if ( (int)me->query_temp("biao") )
		{
	                command("say “你还没有完成刚才给你的任务呢！”");
			return 1;
		}
		coun = 1 + random(sizeof(tar));
		if ( coun == sizeof(tar) )
			coun = ( sizeof(tar) - 1 );
		targ = tar[coun];
		printf("%d/%d\n",coun,sizeof(tar));
		say("唐镖说道:“我这里上好的" + targ + "不多了，你去后山给我找一些来吧！”\n");
//		say("唐镖说道:“你去储藏室可以领到要用的工具！”\n");
		me->set_temp("biao",coun);
	}
	return 1;
}

int give_anqi()
{

}

int accept_object(object who, object ob)
{
	command("say 要是找到了，就放到储藏室去吧！给我干什么?");
	write("唐镖冲着你不耐烦的挥了挥手，低着头接着研究暗器图谱。\n");
	return 0;
}