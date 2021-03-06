// xiaoer2.c 绸缎庄小二

inherit F_DEALER;

void create()
{
	set_name("店小二", ({ "xiao er", "xiao", "waiter" }) );
	set("gender", "男性" );
	set("age", 22);
	set("title", "家和绸缎庄跑堂");
	set("long",
		"这位店小二正笑咪咪地站著，招呼着来来往往的行人。\n");
	set("combat_exp", 1000);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
	set("vendor_goods", ({
//		__DIR__"obj/beixin",
//		__DIR__"obj/pixue",
//		__DIR__"obj/tiejia",
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{	
	object ob; 

	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，进来看看新到的衣服吧。\n");
			break;
		case 1:
			say( "店小二鞠了个躬，说道：这位" + RANK_D->query_respect(ob)
				+ "，请进请进。\n");
			break;
	}
}
