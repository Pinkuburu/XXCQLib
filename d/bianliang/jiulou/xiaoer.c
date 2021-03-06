// xiaoer2.c 酒店小二

inherit F_DEALER;
int ask_me1();
int ask_me2();

void create()
{
	set_name("店小二", ({ "xiao er", "xiao", "waiter" }) );
	set("gender", "男性" );
	set("age", 22);
	set("title", "叁合楼宴宾厅跑堂");
	set("long",
		"这位店小二正笑咪咪地忙著，已经累得满头大汗了。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("no_get", "1");
	set("rank_info/respect", "小二哥");
	set("vendor_goods", ({
		"d/bianliang/npc/obj/dhjiudai",
		"d/bianliang/npc/obj/shaoji",
		"d/bianliang/npc/obj/kaoya",
	}));
        set("inquiry", ([
                "定酒席" : (: ask_me1 :),
                "赴宴" : (: ask_me2 :),
        ]) );
	setup();
	carry_object("clone/misc/cloth")->wear();
}

void init()
{	
	object ob; 

	ob = this_player();

	::init();
	remove_call_out("greeting");
	call_out("greeting", 1, ob);

	add_action("do_buy", "buy");
	add_action("do_list", "list");
	add_action("do_qinghe", "qinghe");
}

int ask_me1()
{
	command("say 我这里定酒席100两黄金一桌，多少人赴宴不限。\n");
	return 1;
}

int ask_me2()
{
	if (this_player()->query_temp("marks/赴宴")) {
		command("say 哦！你是来赴宴的快请进吧！");
		this_player()->move(__DIR__"sanhelou21");
		return 1;
	}
	command("say 你并没有被邀请来赴宴啊！");
	return 1;
}

int accept_object(object who, object ob)
{
	if(ob->query("money_id") && (ob->value() >= 1000000)) {
		command("say 这位客官，您定的酒席要庆贺什么呢？指令格式：qinghe <内容>");
		who->set_temp("marks/定金",1);
		return 1;
	}
	return 0;
}

int do_qinghe(string arg)
{
	object me;
	me = this_player();

        if( !me->query_temp("marks/定金") ) return 0;

	if( !arg ) return notify_fail("指令格式：qinghe <内容> \n");

	me->set_temp("marks/内容", arg);
	command("say 这位客官，您要庆贺"+arg+"，好！请到宴会厅稍候，我准备去。");
	command("say 您现在可以邀请(yaoqing)你所要请的客人。");
	command("say 邀请完后你可以告诉(answer)我开席。");
	me->set_temp("marks/主人",1);
	me->delete_temp("marks/定金");
	me->move(__DIR__"sanhelou21");
	return 1;
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，你是要定酒席吧？\n");
                        break;
                case 1:
                        say( "小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，请坐请坐。\n");
                        break;
        }
}
