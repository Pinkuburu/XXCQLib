// kid.c
// By adx @ CuteRabbit 22:21 99-3-19

inherit NPC;

void create()
{
	set_name("小孩",({ "kid" }) );
        set("gender", "男性" );
	set("per", 16);
        set("age", 7);
        set("long", "这是个农家小孩子\n");
        set("combat_exp", 50);
	set("shen_type", 1);
	set("str", 11);
	set("dex", 11);
	set("con", 11);
	set("int", 11);
        set("attitude", "friendly");

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

