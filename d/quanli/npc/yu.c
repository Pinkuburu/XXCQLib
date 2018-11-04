// yukuyu.c 余哭余	

#include <ansi.h>

inherit NPC;
int ask_box();

void create()
{
	set_name("余哭余",({"yu kuyu","yu"}));
	set("long",
	"余哭余用毒功夫不下唐大和华孤坟，权力帮十九人魔之一。\n"
	"他长有一张大脸，然而眼睛，鼻子，嘴巴都极小极小，时而发出\n"
	"沙哑的哈哈声。\n");
	set("party/rank",HIC"瘟疫人魔"NOR);
    set("accept",2000);
	set("party/party_name","权力帮");
	set("age",52);
	set("gender","男性");
	set("autitude","friendly");
	set("str",22);
	set("con",24);
	set("dex",31);
	set("int",30);
	
	set("max_qi",3000);
	set("max_jing",2000);
	set("neili",3000);
	set("max_neili",3000);
	set("jiali",50);
	
	set("combat_exp",1500000);
	set("score",2000);
	
	set("inquiry",([
		"权力帮":"我愿为权力帮赴汤蹈火，尽忠尽力！",
		]));
			
    set_skill("dodge",150);
    set_skill("force",150);
    set_skill("gudu",200);
    set_skill("parry",150);
    set_skill("poison",200);
	
        set("inquiry", ([
                "gudu" : (: ask_box :),
                "蛊毒之术" : (: ask_box :),
        ]) );
	setup();
	
	carry_object("/clone/misc/cloth")->wear();

	
}
#include "quanli.h"

void init()
{
::init();
add_action("do_skills","skills");
add_action("do_skills","cha");
add_action("do_join","join");
}
int do_skills(string arg)
{
        object ob ;
        ob = this_player () ;
        if( !arg || arg!="yu" )
                return 0;
        if(wizardp(ob))  return 0;
        if (ob->query("party/party_name") != "权力帮")
        {
                message_vision("$N摇了摇头。\n",this_object());
                command("tell "+ob->query("id")+" 不是权利帮的人不能察看。\n"); 
                return 1;
        }
    command("tell "+ob->query("id")+" 我所有的武功如下：\n"+
"※ 余哭余目前所学过的技能：    \n"+
"\n  基本轻功 (dodge)                         - 出神入化 150/    0    \n"+
"  基本内功 (force)                         - 出神入化 150/    0        \n"+
"  基本招架 (parry)                         - 出神入化 150/    0      \n"+
"  蛊毒之术 (gudu)                          - 略知一二 200/    0       0/    0     \n"+
"  基本毒技 (poison)                        - 半生不熟 200/    0       0/    0       \n");
   return 1;
}
int ask_box()
{
   object obj,me = this_player();
   if( me->query_skill("gudu",1) < 100 )
   {  command("say 你的蛊毒之术还不行，我不能把蛊盒交给你!\n");
     return 1;
     }
    command("ok");
    command("say 我将蛊盒给你，要好好的利用他，让他们尝尝权力帮的厉害!\n");
   obj = new("/d/quanli/npc/obj/box");
   obj->move(me);
    return 1;
}
