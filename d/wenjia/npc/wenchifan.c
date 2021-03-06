// NPC: wenchifan.c
// Created by Zeus 1999.3.27
// Modified by Zeus 1999.4.3
// 
// 

inherit NPC;

void greeting(object);
void init();
void serve_tea(object);
void delete_served();

void create()
{
        set_name("温吃饭", ({ "chifan", "wen chifan"}) );
        set("gender", "男性" );
        set("age", 20+random(10));
        set("long",
                "温吃饭是温家总堂里有名的厨师。看上去胖胖的，一副名厨的像。\n");
        set("combat_exp", 10000);
        set("attitude", "friendly");
        set("rank_info/respect", "厨师");
        add_money("silver", 10);
        setup();
}

void init()
{	
        object ob;

        ::init();

        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

	say("温吃饭看见有人进来，停下手中的活，说道：“这位" + RANK_D->query_respect(ob)
	     + "想要什么东西，就向我招手。”\n");
}


void serve_tea(object who)
{
        object obt, obc, obn;
        object room;

        if( !who || environment(who) != environment() ) return;

        if( !objectp(room = environment()) ) return;

        obn = new("/d/wenjia/obj/xingshencha");
        obn->move(room);
        message_vision("温吃饭端来一壶醒神茶，说道：“这可是珍品。”\n",who);

        switch( random(2) )
        {
        case 0:
                obn = new("/d/wenjia/obj/baiqieji");
                obn->move(room);
                message_vision("温吃饭将一碟刚出炉的白切鸡放在桌上。\n", who);
		
                break;
       	case 1: 
                obn = new("/d/wenjia/obj/ruzhu");
                obn->move(room);
                message_vision("温吃饭将一碟乳猪端上桌。\n", who);
	        	
        	break;
	}       	
	
        return;
}
