// NPC 伙计
// By 山猫Adx 16:53 99-10-25

#include <ansi.h>
inherit NPC;
//inherit F_DEALER;

void create()
{
	set_name("伙计", ({ "huo ji", "huo", "ji" }) );
	set("title", HIB"药王谷"NOR+YEL"跑堂"NOR);
	set("gender", "男性" );
	set("age", 22);
	set("combat_exp", 100);
	set("attitude", "friendly");

	setup();
        add_money("silver", 5);
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
	int i=(ob->query("eff_qi")*100)/ob->query("max_qi");

	if((string)ob->query("party/party_name")==HIB"药王谷"NOR) {
		command("say 这位兄弟辛苦了，快请进！\n");
		return 1;}

	if (i<=30) {
		command("wa "+ob->query("id"));
		command("say "+RANK_D->query_respect(ob)
			+"，你受了重伤啊！快请到里面让药王谷医师给你看看吧！\n");
		return 1;}

	if (i<=60) {
		command("look "+ob->query("id"));
		command("say "+RANK_D->query_respect(ob)
			+"，你伤得不轻啊！快请到里面疗伤吧！\n");
		return 1;}

	if (i<=90) {
		command("pat "+ob->query("id"));
		command("say "+RANK_D->query_respect(ob)
			+"，你受了点伤！到里面买包药服下就没事了！\n");
		return 1;}

	else {
	switch( random(4) ) {
		case 0:
			command("bow "+ob->query("id"));
			break;
		case 1:
			command("nod "+ob->query("id"));
			break;
		case 2:
			command("hi "+ob->query("id"));
			break;
		case 3:
			command("welcome "+ob->query("id"));
			break;
		}
	}
}

