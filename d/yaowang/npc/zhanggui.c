// NPC 掌柜
// By 山猫Adx 16:53 99-10-25

#include <ansi.h>
inherit NPC;

int ask_me();
int ask_ok();

void create()
{
	set_name("迟未", ({ "chi wei", "chi", "wei" }) );
	set("title", HIB"药王谷"NOR+WHT"管事"NOR);
	set("long", "他是回春堂的帐房先生，负责回春堂的杂役。\n" );
	set("gender", "男性" );
	set("age", 52);
	set("combat_exp", 100);
	set("attitude", "friendly");

        set("inquiry", ([
		"job" : (: ask_me :),
		"ok" : (: ask_ok :),
        ]));

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

int ask_me()
{
	object ob, me;
	me = this_player();

	if( me->query("party/party_name")!=HIB"药王谷"NOR ) {
		command("say 你不是这里的伙计，这种活怎么能让你干呢？\n");
		return 1; }

	if( (int)me->query_skill("healing",1)>=20 ) {
		command("say 你不需要干这种活的！\n");
		return 1; }

	if ( !me->query_temp("renwu_name") ) {
		ob = new(__DIR__"obj/saoba");
		ob->move(me);
		message_vision(YEL"迟未给了$N一支扫把。\n"NOR, me);
	switch ( random(7) ) {
	case 0 :
		me->set_temp("renwu_name","休息室");
		command("say 你去打扫(dasao)一下休息室吧！\n");
		return 1;
	case 1 :
		me->set_temp("renwu_name","北厅");
		command("say 你去打扫(dasao)一下北厅吧！\n");
		return 1;
	case 2 :
		me->set_temp("renwu_name","正厅");
		command("say 你去打扫(dasao)一下正厅吧！\n");
		return 1;
	case 3 :
		me->set_temp("renwu_name","庭院");
		command("say 你去打扫(dasao)一下庭院吧！\n");
		return 1;
	case 4 :
		me->set_temp("renwu_name","回春堂");
		command("say 你去打扫(dasao)一下大门吧！\n");
		return 1;
	case 5 :
		me->set_temp("renwu_name","内屋");
		command("say 你去打扫(dasao)一下内屋吧！\n");
		return 1;
	case 6 :
		me->set_temp("renwu_name","南厅");
		command("say 你去打扫一下南厅吧！\n");
		return 1;
		}
	}
	else {
		command("say 你先把活干完吧！\n");
		return 1;
	}
}

int ask_ok()
{
	object money, me;
	int amount, i;

	me = this_player();
	amount = random(10);
          i = random(7);
	if ( me->query_temp("renwu_wancheng")==100 ) {
		me->delete_temp("renwu_wancheng");
		me->delete_temp("renwu_name");
		if ( present("saoba", me) ) {
			message_vision ("$N放下手中的扫把。\n", me);
			destruct(present("saoba", me));
        	        money = new ("/clone/money/silver");
                	money->move(me);
			money->add_amount(amount);
			command("say 好！干得不错，这是赏你的！\n");
			if(i=1) {me->add("max_jingli",1);}
		} else { 
			command("hmm "+me->query("id"));
			command("say 真没用，让你干活，你把工具都丢了！\n");
			}
	} else {
		command("say 你赶快去把活干完啊！\n");
		}
        return 1;
}
