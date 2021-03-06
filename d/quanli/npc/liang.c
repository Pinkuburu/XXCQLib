// liangxiaoshu.c 梁消暑	

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("梁消暑",({"liang xiaoshu","liang"}));
	set("long",
	"梁消暑号称佛口，实际上是笑里藏刀，让人放松警惕，然后杀人于松懈\n"
	"之中。\n"
	"他一脸笑嘻嘻，无所谓的样子，看似像一个普通乞丐，却背有七个破\n"
	"布袋。\n");
	set("party/rank",HIC"佛口人魔"NOR);
	set("party/party_name","权力帮");
	set("age",33);
	set("gender","男性");
	set("autitude","friendly");
	set("str",25);
	set("con",30);
	set("dex",28);
	set("int",27);
	
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
			
	set_skill("dodge",180);
	set_skill("force",180);
	set_skill("sword",200);
	set_skill("unarmed",120);
	
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
        if( !arg || arg!="qu" )
                return 0;
        if(wizardp(ob))  return 0;
        if (ob->query("party/party_name") != "权力帮")
        {
                message_vision("$N摇了摇头。\n",this_object());
                command("tell "+ob->query("id")+" 不是权利帮的人不能察看。\n"); 
                return 1;
        }
    command("tell "+ob->query("id")+" 我所有的武功如下：\n"+
"※屈寒山目前所学过的技能       \n"+
"  基本轻功 (dodge)                         - 深不可测 200/    0        \n"+
"  基本内功 (force)                         - 深不可测 200/    0        \n"+
"  基本招架 (parry)                         - 深不可测 200/    0        \n"+
"  基本剑法 (sword)                         - 深不可测 220/    0        \n"+
"  读书写字 (literate)                      - 初窥门径 180/    0       0/    0  \n"+
"★无形之剑 (wuxing-jian)                   - 半生不熟 220/    0       0/    0  \n");
   return 1;
}
