// NPC: chuzi.c
// Created by Zeus 1999.3.27
// Modified by M.A.D. 1999.7.21
// 
// 

inherit NPC;

void greeting(object);
void init();
void serve_tang(object);
void delete_served();

void create()
{
        set_name("厨子", ({ "chuzi"}) );
        set("gender", "男性" );
        set("age", 20+random(10));
        set("long",
                "飞鱼堂里有名的厨师。看上去又矮又胖的，一副名厨的像。\n");
        set("combat_exp", 10000);
        set("attitude", "friendly");
        set("rank_info/respect", "厨师");

	create_family("飞鱼塘", 5, "弟子");

        setup();

        add_money("silver", 10);
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

	say("厨子看见有人进来，停下手中的活，说道：“这位" + RANK_D->query_respect(ob)
	     + "想要什么东西，就向我招手。”\n");
}


void serve_tea(object who)
{
        object obn;
        object room;

        if( !who || environment(who) != environment() ) return;

        if( !objectp(room = environment()) ) return;

        obn = new("/d/feiyu/obj/tang");
        obn->move(room);
        message_vision("厨子端来一碗汤，说道：“请慢用。”\n",who);

        switch( random(2) )
        {
        case 0:
                obn = new("/d/feiyu/obj/kaoya");
                obn->move(room);
                message_vision("厨子将一碟刚出炉的烤鸭放在桌上。\n", who);
		
                break;
       	case 1: 
                obn = new("/d/feiyu/obj/ruzhu");
                obn->move(room);
                message_vision("厨子将一碟乳猪端上桌。\n", who);
	        	
        	break;
	}       	
	
        return;
}
