// NPC 帐房 接纳加入药王谷
// By 山猫Adx 16:53 99-10-25

#include <ansi.h>
inherit NPC;

int ask_join();
int ask_box();

void create()
{
	set_name("郭老六", ({ "guo laoliu", "guo", "laoliu", }));
	set("title", HIB"药王谷"NOR+WHT"管事"NOR);
	set("long", "他是回春堂的帐房先生，负责回春堂的所有帐目。\n" );
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

        set("inquiry", ([
		"药王谷" : (: ask_join :),
		"回春堂" : (: ask_join :),
		"join" : (: ask_join :),
		"加入" : (: ask_join :),
		"打工" : (: ask_join :),
		"针灸盒" : (: ask_box :),
		"box" : (: ask_box :),
        ]));

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
	if(ob->query_temp("naiyaoer")) {
		command("say 谷主正在药王谷等你，你还不快去！\n");
		return 1; }
	if((string)ob->query("party/party_name")==HIB"药王谷"NOR) {
		if( (int)ob->query_skill("healing",1)>=20
		&& ob->query("party/rank")==YEL"跑堂"NOR ) {
		ob->set_temp("naiyaoer",1);
		command("say 这位兄弟你的医药口诀大有长进，正是我药王谷需要的人才！\n");
		command("say 如果你愿意可以到药王谷去，叩见谷主进一步学习。\n");
		return 1;}
		if( (int)ob->query_skill("healing",1)>=40
		&& ob->query("party/rank")==MAG"庄丁"NOR ) {
		ob->set_temp("naiyaoer",2);
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


int ask_join()
{
	mapping party; 
	object me;
	me=this_player();

	if( me->query("party/party_name") == HIB"药王谷"NOR ) {
		command("say "+RANK_D->query_respect(me)+
			"你已经是药王谷的人了，还要加入什么？\n");
		return 1; }

	if( me->query("party") ) {
		command("say "+RANK_D->query_respect(me)+
			"你还是先退出"+me->query("party/party_name")+"吧！\n");
		return 1; }

	if( me->query("yaowang") ) {
		command("say "+RANK_D->query_respect(me)+
			"你本谷总管大弟子禁止你加入！\n");
		return 1; }

	party = allocate_mapping(4);
	party["party_name"] = HIB"药王谷"NOR;
	party["rank"] = YEL"跑堂"NOR;
	party["level"] = 1;
	party["enter_time"] = time();
	me->set("party", party);

	command("ok "+me->query("id"));
	command("say 药王谷就收下你了！\n");

	command("say "+RANK_D->query_respect(me)+
		"今后要多多努力干活啊！\n");
	return 1;
}

int ask_box()
{
	object ob, me;
	me=this_player();

	if( me->query("party/party_name") != HIB"药王谷"NOR ) {
		command("say "+RANK_D->query_respect(me)+
			"你不是药王谷的弟子，针灸盒不能随便给你！\n");
		return 1; }

	if( present("zhenjiu he", me) ) {
		command("say "+RANK_D->query_respect(me)+
			"你现在身上不是有吗？要哪么多干什么呢？\n");
		return 1; }

	if( (int)me->query_skill("healing",1)<40 ) {
		command("say "+RANK_D->query_respect(me)+
			"你现在还不会使用针灸盒！\n");
		return 1; }

	ob = new(__DIR__"obj/zhenjiu");
	ob->move(me);

	message_vision(YEL"郭老六给$N一个" + ob->query("name") + "。\n"NOR, me);

	command("say "+RANK_D->query_respect(me)+
		"今后要多多努力啊！\n");
	return 1;
}
