//By 山猫adx by snow 99-12-5

inherit NPC;
#include <ansi.h>

int	ask_me();
int	ask_ok();

void create()
{
        set_name("天行者", ({ "motobaby","moto" }));
        set("title","天蝉子"+WHT"小雪初晴神雪山"+HIY"山主"NOR);
        set("long", "天行者在神雪山也忙了几十年了，仍勇于提携后生。\n");
        set("gender", "男性");
        set("age", 65);

        set_skill("dodge", 50);
        set_skill("force", 50);
        set_skill("parry", 50);
        set_skill("unarmed", 50);
        set_skill("sword", 50);
        set_skill("blade", 50);
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/damage", 20);

        set("combat_exp", 400000);
        set("shen_type", 1);

        set("inquiry", ([
		"job" : (: ask_me :),
		"ok" : (: ask_ok :),
        ]));
        setup();
	carry_object("/clone/misc/cloth")->wear();
}

int ask_me()
{
	object me, ob;

	me = this_player();
	if ( !(int)me->query_temp("renwu") ) {
	switch ( random(7) ) {
	case 1 :
		me->set_temp("renwu",1);
        	ob=new(__DIR__"obj/mabu");
        	ob->move(me);
		command("say "+me->query("name")+"你拿着抹布，到兵器室帮忙擦武器。"
			+HIC+"(ca 武器)\n"NOR);
		return 1;
	case 2 :
		me->set_temp("renwu",2);
        	ob=new(__DIR__"obj/hammer");
        	ob->move(me);
		command("say "+me->query("name")+"你拿着铁锤，到打铁铺帮忙打铁。"
			+HIC+"(da 铁)\n"NOR);
		return 1;
	case 3 :
		me->set_temp("renwu",3);
        	ob=new(__DIR__"obj/chaidao");
        	ob->move(me);
		command("say "+me->query("name")+"你拿着柴刀，到杂货店帮忙砍柴。"
			+HIC+"(kan 柴)\n"NOR);
		return 1;
	case 4 :
		me->set_temp("renwu",4);
        	ob=new(__DIR__"obj/shichu");
        	ob->move(me);
		command("say "+me->query("name")+"你拿着石杵，到药店帮忙舂药。"
			+HIC+"(chong 草药)\n"NOR);
		return 1;
	case 5 :
		me->set_temp("renwu",5);
        	ob=new(__DIR__"obj/shanzi");
        	ob->move(me);
		command("say "+me->query("name")+"你拿着扇子，到茶馆帮忙烧水。"
			+HIC+"(shao 水)\n"NOR);
		return 1;
	case 6 :
		me->set_temp("renwu",6);
        	ob=new(__DIR__"obj/caidao");
        	ob->move(me);
		command("say "+me->query("name")+"你拿着菜刀，到酒楼帮忙切菜。"
			+HIC+"(qie 菜)\n"NOR);
		return 1;
		}
	}
	else {
		command("say "+me->query("name")+"你还是先把手头的活干完吧！\n"NOR);
		return 1;
	}
}

int ask_ok()
{
	object me;
	int amount;

	me = this_player();
	amount = random(3000);
	if ( (int)me->query_temp("renwu")==100 ) {
		me->delete_temp("wancheng");
		me->delete_temp("renwu");

		me->add("balance", amount);
		command("say 好吧！"+me->name()+
		"干得不错，赏你"+MONEY_D->price_str(amount)+"存入钱庄你的帐户了！");
	}
	else {
		command("say "+me->name()+"快点把你手上的活干完啊！");
		}
        return 1;
}

int recognize_apprentice(object ob)
{
        if ((int)ob->query("newbie")!=1) return 0;
        return 1;
}
