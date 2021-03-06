// NPC 伙计
// By 山猫Adx 16:53 99-10-25

#include <ansi.h>
inherit NPC;
//inherit F_DEALER;

string ask_me(string);
void create()
{
	set_name("伙计", ({ "huo ji", "huo", "ji" }) );
	set("title", HIB"药王谷"NOR+YEL"跑堂"NOR);
	set("gender", "男性" );
	set("age", 22);
	set("combat_exp", 100);
	set("attitude", "friendly");

        set("inquiry", ([
		"食物" :   (: ask_me, "baozi" :),
		"水" :   (: ask_me, "jiudai" :),
        ]));
	set("vendor_goods", ({
		"/clone/misc/jinchuang",
		"/clone/misc/baiyao",
	}));
	set("foor_count", 10);
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
	if(ob->query_temp("naiyaoer")) {
		command("say 谷主正在药王谷等你，你还不快去！\n");
		return 1; }
	if((string)ob->query("party/party_name")==HIB"药王谷"NOR) {
		if( (int)ob->query_skill("healing",1)>=60
		&& ob->query("party/rank")==HIM"药匠"NOR ) {
		ob->set_temp("naiyaoer",3);
		command("say "+ob->query("name")+"谷主吩咐你速去见他！\n");
		return 1;}
		if( (int)ob->query_skill("healing",1)>=80
		&& ob->query("party/rank")==CYN"药师"NOR ) {
		ob->set_temp("naiyaoer",4);
		command("say "+ob->query("name")+"谷主吩咐你速去见他！\n");
		return 1;}
		if( (int)ob->query_skill("healing",1)>=100
		&& ob->query("party/rank")==HIC"医师"NOR ) {
		ob->set_temp("naiyaoer",5);
		command("say "+ob->query("name")+"谷主吩咐你速去见他！\n");
		return 1;}
	}
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

string ask_me(string name)
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("party")) || fam["party_name"] != HIB"药王谷"NOR)
		return RANK_D->query_respect(this_player()) + 
		"你与本谷素无来往，不知此话从何谈起？";

	if (  present(name, this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"你现在身上不是有吗，怎麽又来要了？别人都还没吃饭呢！";

	if (query("foor_count") < 1)
		return "抱歉，你来得不是时候，开饭的时间已经过了。";

	ob = new("/clone/food/" + name);
	ob->move(this_player());

	add("foor_count", -1);

	message_vision(YEL"伙计给$N一个" + ob->query("name") + "。\n"NOR, this_player());

	return "给。";
}
