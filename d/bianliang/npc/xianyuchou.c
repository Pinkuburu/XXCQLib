// longchuichui.c 

inherit NPC;

#include <ansi.h>

void create()
{
	set_name("鲜于仇", ({ "xian yuchou", "xian", "yuchou" }));
	set("long", 
"他长着一张方脸，下颌几缕黄色苍须，不时的皱一皱眉头，\n"
"显得很是脾气暴躁的样子。\n");
	set("gender", "男性");
	set("age", 20);
        set("title", "汴梁城驻军管带");
	set("nickname", HIC"骆驼老爷"NOR);
	set("attitude", "peaceful");
	set("shen_type", -1);
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

	carry_object(__DIR__"obj/jinjia")->wear();
	carry_object(__DIR__"obj/tieguai")->wield();
}

void init()
{	
	::init();
	add_action("do_kill","kill");
	add_action("do_kill","fight");
}

int do_kill()
{
	object ob,me;
	ob = this_player();
	me = this_object();
	message_vision("$N对著$n大喝一声：在本官面前闹事，你是活得不耐烦了吧！\n", me, ob);
	me->kill_ob(ob);
	ob->kill_ob(me);
	return 1;
}
