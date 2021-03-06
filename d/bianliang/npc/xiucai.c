// xian. 冼老板

inherit F_DEALER;
int ask_book();

void create()
{
	set_name("刘秀才", ({ "liu xiucai", "liu", "xiucai" }));
	set("title", "三友书庄");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "男性");
	set("age", 45);
	set("long", "一个身着长衫中年男子，据说学问不小，不知道该买什么书可以问问他。\n");
	set("combat_exp", 50000);
        set("qi", 300);
        set("max_qi", 300);
	set("attitude", "friendly");
	set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
	set("vendor_goods", ({
		__DIR__"obj/sanzijing",
		__DIR__"obj/sanguo",
		__DIR__"obj/daxue",
		__DIR__"obj/sanwen",
		__DIR__"obj/shijing",
		__DIR__"obj/libai",
        __DIR__"obj/zhuxi",
	}));

        set("inquiry", ([
                "book" : (: ask_book :),
        ]) );

	setup();
        add_money("silver", 20);
	carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

int ask_book()
{
	int lv = this_player()->query_skill("literate",1);

	if (lv < 31)
		command("say 我看这位"+RANK_D->query_respect(this_player())+"学问尚浅，恐怕读不了这里的书，还是去学堂上学为好。");
	else if (lv < 50)
		command("say 这位"+RANK_D->query_respect(this_player())+"读读这本三国志如何？");
	else if (lv < 70)
		command("say 这位"+RANK_D->query_respect(this_player())+"颇有学识，这本李白全集应该正好适合您。");
	else if (lv < 90)
		command("say 这位"+RANK_D->query_respect(this_player())+"谈吐不凡，应该可以读这本诗经了。");
	else if (lv < 110)
		command("say 我这里这本大学章句好久没人买了，这位"+RANK_D->query_respect(this_player())+"应该配读此书。");
	else if (lv < 120)
		command("say 这里除了这本古散文集恐怕再没有别的入这位"+RANK_D->query_respect(this_player())+"的法眼了。");
    else if (lv < 180)
        command("say 好吧，我只有把我收藏的《朱熹文集》都拿出来给这位"+RANK_D->query_respect(this_player()));
	else
		command("say 您到小店小店蓬壁生辉，但小店实在没有适合您读的书，真抱歉。");

	return 1;
}
