// ding.c 家丁

inherit NPC;

void create()
{
	set_name("小流氓", ({ "xiao liumang", "xiao", "liumang" }));
	set("age", 19);
	set("gender", "男性");
	set("long", "一个看上去流里流气的年轻人，不时的哼着小调。");
	set("attitude", "peaceful");

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 1000);
	set("shen", -500);

	set_skill("strike", 10);
	set_skill("dodge", 20);
	set_skill("parry", 10);
	set_skill("force", 10);

	set("chat_msg", ({
		"小流氓流里流气的唱：“路边的野花，不采白不采~~~~。”\n",
		"小流氓左顾右盼，不知在找什么。”\n",
	}));

	setup();

	carry_object("/clone/misc/cloth")->wear();
}