// longchuichui.c 

inherit NPC;

#include <ansi.h>

void create()
{
	set_name("士兵", ({ "shi bing", "bing" }));
	set("long", 
"这个士兵脸上看上去瘦瘦的，每天就负责守卫营门，\n"
"如果真的打起仗来不知道顶不顶用。\n");
	set("gender", "男性");
	set("age", 20);
        set("title", "汴梁城兵营守卫");
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 18);
	set("int", 25);
	set("con", 20);
	set("dex", 20);
	
	set("max_qi", 1200);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 50);
	set("combat_exp", 100000);
	set("score", 8000);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("club", 100);
	set_skill("strike", 100);
	set_skill("cuff", 100);

	setup();

	carry_object(__DIR__"obj/junfu")->wear();
	carry_object(__DIR__"obj/dgqiang")->wield();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

	add_action("do_kill","kill");
	add_action("do_kill","fight");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "士兵用冰冷冷的眼光上下打量着你。\n");
			break;
		case 1:
			say( "士兵大声喊道：“兵营前面不得逗留，快走快走！！！”\n");
			break;
	}
}

int do_kill()
{
	object ob,me;
	ob = this_player();
	me = this_object();
	message_vision("$N对著$n大喝一声：在兵营前面闹事，你是活得不耐烦了吧！\n", me, ob);
	me->kill_ob(ob);
	ob->kill_ob(me);
	return 1;
}