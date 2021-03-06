// Npc: /kungfu/class/shaolin/qing-guan.c
// Date: YZC 96/01/19

inherit NPC;


void create()
{
	set_name("天斗", ({	"tian dou", "tian", "dou",}));
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

	setup();

        carry_object(__DIR__"obj/heijiasha")->wear();
        carry_object(__DIR__"obj/sengxie")->wear();
}

void init()
{
	object me, ob;
	mapping fam;

	::init();

	ob = this_player();
	me = this_object();
	
	if (interactive(ob) 
	&& !environment(ob)->query("no_fight")
	&& !present("yingxiong ling", ob) 
	&& ( (fam = ob->query("family")) && fam["family_name"] != "少林派" ) )
	{
		if( !ob->query_temp("warned") ) {
			command("hmm");
			command("say 滚!!！");
			ob->set_temp("warned", 1);
		}
		else if( ob->query_temp("stay") < 10 ) ob->add_temp("stay", 1);
		else {
			command("say 大胆狂徒，竟敢闯到少林寺里来撒野！！！\n");
			me->set_leader(ob);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
		}
	}       

}
