// Room: /welcome/npc/netplay.c
//By adx @ CuteRabbit 15:57 99-5-18

inherit NPC;
#include <ansi.h>

void create()
{
        set_name("教习", ({ "jiaoxi" }));
        set("title",WHT"小雪初晴神雪山"NOR);
        set("long", "他是神雪山的教习，负责传授武功。\n");
        set("gender", "男性");
        set("age", 65);

        set_skill("dodge", 50);
        set_skill("force", 50);
        set_skill("parry", 50);
        set_skill("unarmed", 50);
        set_skill("sword", 50);
        set_skill("blade", 50);

        set("combat_exp", 4000);
        set("shen_type", 1);
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

int recognize_apprentice(object ob)
{
         if ((int)ob->query("newbei")!=1) return 0;
        return 1;
}

int accept_fight(object ob)
{
	object me  = this_object();
/*
	if (me->query("age") < 15)
	{
		command("laugh " + ob->query("id"));
		command("say " + RANK_D->query_respect(ob) + 
             "你现在还小，在神雪山多学习一段时间吧 !\n");
		return 0;
	}
*/
    if (me->query("newbei")==1)
	{
		remove_call_out("checking");
		call_out("checking", 1, me, ob);
		return 1;
	}
	else {
		command("kick " + ob->query("id"));
		command("say " + RANK_D->query_respect(ob) + 
             "不必和我较量，可以离开神雪山了 !\n");
		return 0;
	}
}

int checking(object me, object ob)
{

	int my_max_qi, his_max_qi;

	my_max_qi  = me->query("max_qi");
	his_max_qi = ob->query("max_qi");

	if (me->is_fighting()) 
	{
		call_out("checking",2, me, ob);
                return 1;
	}

	if ( !present(ob, environment()) ) return 1; 

	if ( (((int)me->query("qi")*100 / my_max_qi) <= 50) &&
		(me->query("age") >= 15) ) 
	{
		command("ok " + ob->query("id"));
		command("say " + RANK_D->query_respect(ob) + 
             "可以离开神雪山了 ! 恭喜你了 !\n");
                command("say 在江湖中生存需要的不仅仅武功，你要学的还很多！");
                 command("say 今后多多努力，多象老玩家请教！") ;
                 command("say 祝你玩得愉快！"); 
                 command("say 你走吧！");
         ob->delete("newbei");
		return 1;
	}

	if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
	{
		command("papaya " + ob->query("id"));
		command("say 看来" + RANK_D->query_respect(ob) + 
			"还得多加练习，方能在武林中生存 !\n");
		return 1;
	}

	return 1;  
}
