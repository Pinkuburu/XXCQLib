// NPC 药王谷 总管
// By 山猫Adx 16:53 99-10-25

#include <ansi.h>
#ifndef NPCDATA
#define NPCDATA "/d/yaowang/npc/"
#endif
#define MENGZHU NPCDATA + "zongguan"

inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;

string query_save_file()
{
	return MENGZHU;
}

void create()
{
	seteuid(getuid());

	if (!restore()) {
	set_name("总管", ({ "zongguan", "zong", "guan" }) );
	set("title", HIB"药王谷"NOR+HIW"总管"NOR);
	set("gender", "男性" );
	set("age", 40);
	set("attitude", "heroism");
	set("generation",0);
	set("winner","NONE");

	set("no_clean_up",1);

	set_skill("healing", 100);
	setup();
	carry_object("/clone/misc/cloth")->wear();        
	}
	else {
		set("id", "zongguan");
		set_name(query("name"), ({  "zongguan", "zong", "guan" }));
	setup();
	if( this_object()->query("my_weapon") )
		carry_object(this_object()->query("my_weapon"))->wield();
	if( this_object()->query("my_armor") )
		carry_object(this_object()->query("my_armor"))->wear();        
	}
}

void init()
{
	object me, ob;
	mapping party;
	me = this_player();
	ob = this_object();

	if( ob->query_skill("healing", 1) < me->query_skill("healing", 1)
		&& me->query("party/party_name")==HIB"药王谷"NOR
		&& (me->query("party/level")==6 || me->query("party/level")==7)
		&& !wizardp(me) )
	{
		party = allocate_mapping(4);
		party["party_name"] = HIB"药王谷"NOR;
		party["rank"] = HIW"总管"NOR;
		party["level"] = 8;
		party["enter_time"] = time();
		me->set("party", party);

		remove_call_out("checking");
		call_out("checking", 1, me, ob);
	}
	else if(me->query("party/party_name")==HIB"药王谷"NOR
		&& me->query("party/rank")==HIW"总管"NOR
		&& ob->query("zongguan_id")!=me->query("id") )
	{
		write(HIW"你已经不再是药王谷总管了！\n"NOR);
		party = allocate_mapping(4);
		party["party_name"] = HIB"药王谷"NOR;
		party["rank"] = HIG"弟子"NOR;
		party["level"] = 6;
		party["enter_time"] = time();
		me->set("party", party);
	}
	add_action("do_ren", "任命");
	add_action("do_jinzhi", "禁止");
	add_action("do_unjinzhi", "同意");
	add_action("do_kaichu", "开除");
	add_action("do_unjoin","退出");
}

int checking(object me, object ob)
{
	if( ob->query("zongguan_id")!=me->query("id")
		&&ob->query("name")!=me->query("name") )
		write(HIW"恭喜你成为药王谷总管！\n"NOR);

	ob->set_skill("healing", (me->query_skill("healing", 1)) );
	ob->set("name", (me->query("name")) );
	ob->set("zongguan_id", (me->query("id")) );
	ob->set("per", (me->query("per")) );
	ob->set("party", (me->query("party")) );
	ob->set("title", (me->query("title")) );
	save();
	return 1;
}

int do_jinzhi(string arg)
{
	object me, ob;
	mapping party;
	me = this_player();

	if( (!party=me->query("party"))
		|| (party["party_name"]!=HIB"药王谷"NOR)
		|| this_object()->query("zongguan_id")!=me->query("id") )
		return notify_fail("你无权进行此操作！\n");

	if( !arg ) return notify_fail("指令格式：禁止 <ID> \n");

	if( !ob ) ob = find_living(arg);

	if (!ob) return notify_fail("现在没这个人。\n");

	if (ob==me) return notify_fail("你要干什么？？！\n");

	if(ob->query("party/party_name") == HIB"药王谷"NOR)
		return notify_fail("对方是药王谷中人，你只要将他开除就行了！\n");

	if(ob->query("yaowang"))
		return notify_fail("他已经被禁止加入药王谷了。\n");

	ob->set("yaowang",1);
	message_vision(YEL"$N下令永远禁止$n加入药王谷。\n"NOR, me, ob);
	return 1;
}

int do_unjinzhi(string arg)
{
	object me, ob;
	mapping party;
	me = this_player();

	if( (!party=me->query("party"))
		|| (party["party_name"]!=HIB"药王谷"NOR)
		|| this_object()->query("zongguan_id")!=me->query("id") )
		return notify_fail("你无权进行此操作！\n");

	if( !arg ) return notify_fail("指令格式：同意 <ID> \n");

	if( !ob ) ob = find_living(arg);

	if (!ob) return notify_fail("现在没这个人。\n");

	if(!ob->query("yaowang"))
		return notify_fail("他没有被禁止加入药王谷。\n");

	if(ob->query("party/party_name") == HIB"药王谷"NOR)
		return notify_fail("对方已经是药王谷中人了。\n");

	ob->delete("yaowang");
	message_vision(YEL"$N下令允许$n加入药王谷。\n"NOR, me, ob);
	return 1;
}

int do_kaichu(string arg)
{
	object me, ob;
	mapping party;
	me = this_player();

	if( (!party=me->query("party"))
		|| (party["party_name"]!=HIB"药王谷"NOR)
		|| this_object()->query("zongguan_id")!=me->query("id") )
		return notify_fail("你无权进行此操作！\n");

	if( !arg ) return notify_fail("指令格式：开除 <ID> \n");

	if( !ob ) ob = find_living(arg);

	if (!ob) return notify_fail("现在没这个人。\n");

	if (ob==me) return notify_fail("要开除自己？哈哈！你傻得真可爱！\n");

	if(ob->query("party/party_name") != HIB"药王谷"NOR)
		return notify_fail("你真逗！对方又不是药王谷中人，怎么开除？\n");

	ob->delete("party");
	ob->set("yaowang",1);
	message_vision(YEL"$N下令将$n驱逐出药王谷，并且永远禁止$n再加入。\n"NOR, me, ob);
	return 1;
}

int do_unjoin(string arg)
{
	object me, ob;
	me = this_object();
	ob = this_player();

	if( !arg || arg!="药王谷" )
		return notify_fail("你要退出什么？指令格式：退出 药王谷\n");

	if( ob->query("party/party_name") != HIB"药王谷"NOR )
	{
		message_vision(CYN"$N对$n说道：你不是我药王谷的人不用退出。\n"NOR,me,ob);
		return 1;
	}
	ob->delete("party");
	command("sigh "+ob->query("id"));
	command("say 好吧！"+ob->query("name")+"退出了药王谷！");
	return 1;
}

int do_ren(string arg)
{
	object me, ob;
	string id, rank1, rank2;
	int i;
	me = this_player();

	if( (sscanf(arg, "%s %s", id, rank1)!=2) || !arg );
		return notify_fail("指令格式：任命 <ID> <等级>\n"
			"你可以任命的药王谷职位有:\n"
			"        制药管事        制药弟子\n"
			"        炼丹管事        炼丹弟子\n"
			"        回春堂管事      回春堂弟子\n");

	if( !me->query("party")
		|| (me->query("party/name")!=HIB"药王谷"NOR)
		|| this_object()->query("zongguan_id")!=me->query("id") )
		return notify_fail("你无权进行此操作！\n");

	if( !ob ) ob = find_living(id);

	if(!ob) return notify_fail("现在没这个人。\n");

	if(ob==me) return notify_fail("你要任命自己？干啥！\n");

	if(ob->query("party/party_name") != HIB"药王谷"NOR)
		return notify_fail("对方不是药王谷中人，你无权号令他！\n");

	if(rank1=="制药管事") {rank2=WHT"制药管事"NOR;i=7;}
	if(rank1=="炼丹管事") {rank2=WHT"炼丹管事"NOR;i=7;}
	if(rank1=="回春堂管事") {rank2=WHT"回春堂管事"NOR;i=7;}
	if(rank1=="制药弟子") {rank2=HIG"制药弟子"NOR;i=6;}
	if(rank1=="炼丹弟子") {rank2=HIG"炼丹弟子"NOR;i=6;}
	if(rank1=="回春堂弟子") {rank2=HIG"回春堂弟子"NOR;i=6;}

	else return notify_fail("没有该职位！\n");

         ob->set("party/rank", rank2);
         ob->set("party/level", i);
     message_vision(YEL"$N任命$n为"+HIB"药王谷"+rank2+"。\n"NOR, me, ob);
	return 1;
}
