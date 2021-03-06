// NPC 萘药儿 药王谷谷主
// By 山猫Adx 16:53 99-10-25

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("萘药儿", ({ "nai yaoer","nai","yaoer"}));
	set("title", HIB"药王谷谷主"NOR);
	set("gender", "男性");
	set("attitude", "friendly");

	set("age", 60);
	set("shen_type", 1);
	set("str", 17);
	set("int", 16);
	set("con", 18);
	set("dex", 20);
	set("max_qi", 150);
	set("max_jing", 150);
	set("jiali", 10);
	set("combat_exp", 5000);

	set_skill("force", 15);
	set_skill("dodge", 15);
	set_skill("unarmed", 15);
	set_skill("parry", 15);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{	
	object ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

int greeting(object ob)
{
	if( (string)ob->query("party/party_name")!=HIB"药王谷"NOR) {
		command("say 你不是本谷中人，来这里干什么，速速离去。\n");
		return 1; }
	if(!ob->query_temp("naiyaoer")&&ob->query("party/level")<6) {
		command("say 你没事跑到这里干什么，快干活去。\n");
		return 1; }
	if(ob->query_temp("naiyaoer")==1) {
		ob->set("party/party_name",HIB"药王谷"NOR);
		ob->set("party/rank",MAG"庄丁"NOR);
		ob->set("party/level",2);
		ob->delete_temp("naiyaoer");
		command("say "+ob->query("name")+"是郭老六让你来见我的吗？\n");
		command("say 好！你就留在谷中好好修习医药口诀吧！\n");
	}
	if(ob->query_temp("naiyaoer")==2) {
		ob->set("party/party_name",HIB"药王谷"NOR);
		ob->set("party/rank",HIM"药匠"NOR);
		ob->set("party/level",3);
		ob->delete_temp("naiyaoer");
		command("say "+ob->query("name")+"你的医药口诀有些长进。\n");
		command("say 你可以在我药王谷取药材了。\n");
		return 1;
	}
	if(ob->query_temp("naiyaoer")==3) {
		ob->set("party/party_name",HIB"药王谷"NOR);
		ob->set("party/rank",CYN"药师"NOR);
		ob->set("party/level",4);
		ob->delete_temp("naiyaoer");
		command("say "+ob->query("name")+"你的医药口诀大有长进。\n");
		command("say 你可以在我药王谷配制丹药了。\n");
		return 1;
	}
	if(ob->query_temp("naiyaoer")==4) {
		ob->set("party/party_name",HIB"药王谷"NOR);
		ob->set("party/rank",HIC"医师"NOR);
		ob->set("party/level",5);
		ob->delete_temp("naiyaoer");
		command("say "+ob->query("name")+"你的医药口诀长进了很多。\n");
		command("say 你可以在我药王谷的药局坐堂了。\n");
		return 1;
	}
	if(ob->query_temp("naiyaoer")==5) {
		ob->set("party/party_name",HIB"药王谷"NOR);
		ob->set("party/rank",HIG"弟子"NOR);
		ob->set("party/level",6);
		ob->delete_temp("naiyaoer");
		command("say "+ob->query("name")+"你的医药口诀学得很不错。\n");
		command("say 你可以正式成为我药王谷的弟子了。\n");
		return 1;
	}
}
