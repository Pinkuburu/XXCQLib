// mmr.c

#include <ansi.h>

inherit NPC;
int ask_bo();
void create()
{
       	set_name("蒙面老僧", ({ "mengmian laoseng", "old monk", "laoseng" }) );
       	set("long","一位身着灰布僧衣的僧人，脸上蒙着灰布。\n" );       
       	set("gender", "男性" );                
       	set("shen_type", -1);
       	set("age", 70);
       	set("combat_exp", 1800000);
       	set("attitude", "heroism");
       	set("unique", 1);
	set("shen_type", -1);
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	
	set("max_qi", 4500);
	set("max_jing", 4500);
	set("neili", 4500);
	set("max_neili", 4500);
	set("jiali", 0);
	set("combat_exp", 3000000);
	set("score", 50000);                
	set("chat_chance_combat",40);
        set("chat_msg_combat", ({
        (: perform_action, "parry.xingyi" :)
}));
        set_skill("strike",200);
        set_skill("finger",200);
        set_skill("dodge",200);
        set_skill("force", 200);
	set_skill("canhe-zhi", 200);
	set_skill("murong-jianfa",200);       
        set_skill("shenyuan-gong", 200);
	set_skill("yanling-shenfa", 200);
        set_skill("douzhuan-xingyi", 230);
	set_skill("parry", 210);
	set_skill("sword", 200);
	set_skill("literate", 200);
        set_skill("murong-daofa", 200);
        set_skill("blade",200);
        
        map_skill("blade", "murong-daofa");
        map_skill("finger", "canhe-zhi");
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
        map_skill("parry", "douzhuan-xingyi");
	map_skill("sword", "murong-jianfa");

	prepare_skill("finger","canhe-zhi");

       set("inquiry", ([
                "慕容博" : (: ask_bo :),
                "慕容复" : "慕容复，是我儿子，是大燕国唯一的希望了。\n",
       ]));

       setup();       
       
       carry_object("/clone/misc/cloth")->wear();
       add_money("silver", 10);
}


void kill_ob(object me)
{     
      command("grin");
      command("perform xingyi");
      ::kill_ob(me);
}
void init()
{
        object me = this_player();
        ::init();                          
        if(environment(me))
        {
	        if( me->query_temp("mrb_see") )
        	{
      			command("look " + me->query("id"));
	          	command("hehe");
        	  	command("say 你有没有(no)儿子？");
          		me->set_temp("mrb_ask", 1);
        	}     

        	else 
        	{
	        	message_vision("$N一脚把$n踢出丈远。\n", this_object(), me);
        		me->move("/d/murong/hb2");
        		message("vision", me->name()+"被人从柳林里踢了出来。\n", environment(me), ({me}));        	
        	}
        }
	add_action("yes", "yes");
       	add_action("no", "no");
	add_action("do_kneel", "kneel");	          	        
        return;
}

int no()
{
	object me = this_player();   
	if(!me->query_temp("mrb_ask")) return 0;         
	message_vision("\n$N道：我尚未婚配，何来子息？\n", me);
       	me->delete_temp("mrb_see");            
	me->force_me("halt");
	if(environment(me))	                                                            
	{
		remove_call_out("ask");
		call_out("ask", 1, me);                  
	}
	return 1;
}
                                                             
int yes()
{
	object me = this_player();
	if( !me->query_temp("mrb_ask1")) return 0;
	message_vision("\n$N甚是气恼，大声道：当然有！我自愿就死，与你何干？\n", me);
	message_vision(CYN"\n灰衣僧道：你高祖有儿子，你曾祖、祖父、父亲都有儿子，便是你没有儿子！
嘿嘿，大燕国当年慕容世家何等英雄，却不料都变成例如断种绝代的无后之人！\n\n"NOR, me);
	me->delete_temp("mrb_ask1");
	remove_call_out("wait");
	call_out("wait", 3, me);
	return 1;
}                                                            
void ask()
{
	object me = this_player();
	message_vision(CYN"\n灰衣老僧问$N道：你有(yes)没有祖宗？\n"NOR, me);
	me->delete_temp("mrb_ask");
	me->set_temp("mrb_ask1", 1);
	return;
}

void wait()
{
	object me = this_player();
	if(environment(me))
	{
	write("\n你不禁听得老僧一席话，心想：今日我以一时之忿，自寻短见，我鲜卑慕容氏
从此绝后。我连儿子都没有，还说得上甚么光宗复国？不由得全身是汗。
你立刻跪倒(kneel)在地。\n\n");
	me->set_temp("mrb_said", 1);
	}
	return;
}

int do_kneel()
{
	object me = this_player();
	if( !me->query_temp("mrb_said")) return 0;
	message_vision("\n$N当即拜伏在地，说道："+me->name()+"识见短拙，得蒙高僧指点迷津，大恩大得，没齿难忘。\n\n", me);
	me->delete_temp("mrb_said");
	remove_call_out("do_speech");
	call_out("do_speech", 2, me);
	return 1;
}	

void do_speech()
{
	object me = this_player();                                          
	if(environment(me))
	{
		message_vision("\n$N说道：“起来！”$n恭恭敬敬 磕了三个头，站起身来。\n\n", this_object(), me);
		message_vision(CYN"\n$N道：你姑苏慕容的家传武功神奇精奥，举世无双，只不过
你没学到家而已，难道当真就不及大理国段氏的“六脉神剑”了？
瞧仔细了！$N伸出食指，凌虚点了三下。\n\n"NOR, this_object());
	remove_call_out("result");
	call_out("result", 2, me);   	
	}
	return;
}                                 

void result()
{
	object me = this_player();
	object ob;         
	if(environment(me))
	{
	message_vision(HIY"\n只听得喀嚓三声响，树上的一只柳条应声落下。\n\n"NOR, me);
	ob=new("/d/murong/obj/liutiao");
	ob->set("name", "断成三截的柳树条");
	ob->set("weapon_prop/damage", 0);   
	ob->move(environment(me));
	remove_call_out("say");	
	call_out("say", 2, me);
	}
	return;
}                              

void say()
{
	object me = this_player();
	if(environment(me))
	{	
	message_vision(CYN"\n灰衣老僧朗声说道：这便是你慕容家的“参合指”！
当年老衲从你先人处学来，也不过一知半解、学到一些皮毛而已，
慕容氏此外的神妙武功不知还有多少。嘿嘿，难道就凭你这少年
人这一点微末道行，便创得姑苏慕容氏“以彼之道，还施彼身”
的大名么？\n\n"NOR, me);                
	me->set_temp("ask_bo", 1);
	write(HIY"难道这位老僧就是。。。慕容博？？\n"NOR);
	}
	return;
}

int ask_bo()
{       
	object me = this_player();
	object ob = this_object();
	int ask = me->query_temp("ask");	
	if(!me->query_temp("ask_bo")) return 0;
	if(ob->query_temp("changed")) return 0;
	if( ask < 1 )
	{
		command("dunno");
		me->set_temp("ask", 1);        
		return 1;
	}                       
	if( ask >= 1 && ask < 6)
	{
		command("dunno "+ob->query("id"));
		me->add_temp("ask", 1);
		return 1;
	}                              
	if( ask == 6 )
	{
		command("sigh");
		command("whisper "+me->query("id")+" 老朽就是慕容博。");
		me->delete_temp("ask");
		me->delete_temp("ask_bo");		
		ob->set_temp("changed", 1); 
		remove_call_out("change");
		call_out("change", 3, me);
		return 1;
	}

}

void change()
{
	object me = this_player();
	object ob = this_object();
	if(environment(me))
	{
	message_vision("$N解开了蒙在脸上的灰布，露出了本来的面容。\n", ob);
	ob->set("name", "慕容博");                  
	ob->set("title", HIC"以彼之道 还施彼身"NOR);
	ob->set("long", "这位就是天下文明号称以彼之道，还施彼身的姑苏慕容博。\n");
	}
	if( !me->query("meet_mrb"))
	{
		remove_call_out("teach");                      	
		call_out("teach", 2, me);
	}
	return;
}

void teach()
{
      	object me, mrb;
      	int i,lvl=1, level;
	mapping skills;
	string *sk;
      	me = this_player();
      	mrb = this_object();    
        level = (int)me->query_skill("douzhuan-xingyi", 1);
       	if(environment(me) && !me->query("meet_mrb"))
       	{
	      	if(me->query("int") < 27)
      		{       
      			command("say 你我此番相遇，本属缘分，如不传授你些武功，岂不让武林中人以为我慕容无人？");
	        	command("say 本可以与你讲解本门斗转星移的武学要旨，无奈你天生资质太差，只好传功与你了。");
		        command("sigh");
        		skills = me->query_skills();
			if (mapp(skills)) 
			{
				sk = keys(skills);
				for (i=0;i<sizeof(sk);i++)
					skills[sk[i]]+=lvl;
			}
			me->add("combat_exp", 1000);
	      		me->set("potential", i);                                     
		      	me->set("meet_mrb", 1);
		      	tell_object(me, HIC"你的武学修为提高了！\n"NOR);             
	      		call_out("do_back", 15, me);           
	        	return;
        	}     
	      	else
      		{                                    
	      		command("say 我看你资质不错，传授于你斗转星移密要。希望你能光大慕容武学，
真正做到“以彼之道，还施彼身”，嘿嘿！");
        		tell_object(me, HIC "\n慕容博开始给你讲解斗转星移的武学要旨。。。\n" NOR );              
	        	me->set_skill("douzhuan-xingyi", level+5);        
        		me->add("str", 1);
	        	skills = me->query_skills();
			if (mapp(skills)) {
				sk = keys(skills);
				for (i=0;i<sizeof(sk);i++)
					skills[sk[i]]+=lvl;
		}
		me->add("combat_exp", 1000);
	        me->set("meet_mrb", 1);
	      	tell_object(me, HIC"你的武学修为提高了！\n"NOR);             		
	      	remove_call_out("do_back");
		call_out("do_back", 15, me);    
        }
    }           
}

void do_back()
{     
      object me;
      me = this_player();    
      if(environment(me))
      {
	      message_vision(CYN"\n$N大大大笑几声，而后脸上却露出痛苦的神情。\n"NOR, this_object());
	      message_vision(HIY"\n空中忽然几只小燕子在半空飞掠而过。\n\n"NOR,me);
	      remove_call_out("do_leave");
	      call_out("do_leave", 5, me);                   
      }
      return;
}

void do_leave()
{
      object me, mrb;
      me = this_player();
      mrb = this_object();    
      if(environment(me))
      {   
      	      message_vision("$N突然“哎呀”一声，你只觉眼前一花，$N身影早已落到树丈之外。\n", mrb, me);
      	      destruct(mrb);      
      }       
      return;
}