// xian. 冼老板

inherit F_DEALER;

void create()
{
	set_name("胡老板", ({ "xian laoban", "xian" }));
	set("title", "叁合楼老板");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "男性");
	set("age", 45);
	set("long", "胡老板是个懂得和气生财得中年人，经营叁合楼已有二十余年。\n");
	set("combat_exp", 50000);
        set("qi", 300);
        set("max_qi", 300);
	set("attitude", "friendly");
	set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
	set("vendor_goods", ({
		__DIR__"obj/dhjiudai",
		__DIR__"obj/shaoji",
		__DIR__"obj/kaoya",
	}));

	setup();
        add_money("gold", 1);
	carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
