// banker.c
// originally coded by xiang
// 96-02-16 YZC fixed some math problem

inherit F_BANKER;

void create()
{
	set_name("高鸡血", ({"gao jixue", "gao", "jixue"}));
	set("title", "钱庄老板");
	set("nickname", "铁公鸡");
	set("gender", "男性");
	set("long",
		"他就是与韦鸭毛合称“鸡血鸭毛”的高鸡血，他是京城著名的商人\n"
		"，这家钱庄是他在京城的买卖之一。虽然是个商人，单似乎也有些\n"
		"功夫的样子。\n");
	set("age", 34);

	set("str", 22);
	set("int", 24);
	set("dex", 18);
	set("con", 18);

	set("qi", 500); 
	set("max_qi", 500);
	set("jing", 100);
	set("max_jing", 100);
	set("shen", 0);

	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "friendly");
	set("env/wimpy", 50);
	set("chat_chance", 2);
	set("chat_msg", ({
	"高鸡血骄傲的说道：本银号已经有上百年的历史，在京城可以说是第一家。\n",
	}));

	set_skill("strike", 100);
	set_skill("dodge", 100);
	set_skill("parry",100);
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 40);
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
