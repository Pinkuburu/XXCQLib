// shengjiangbei.c 盛江北	

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("盛江北",({"sheng jiangbei","sheng"}));
	set("long",
	"盛江北在十九人魔中可以算是最耿直的，但搏斗经验非常高超。\n"
	"他高大威猛，白发银须，满脸通红。\n");
	set("party/rank",HIC"神拳天魔"NOR);
	set("nickname",HIW"大江龙"NOR);
	set("party/party_name","权力帮");
	set("age",61);
	set("gender","男性");
	set("autitude","friendly");
	set("str",30);
	set("con",25);
	set("dex",23);
	set("int",23);
	
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
