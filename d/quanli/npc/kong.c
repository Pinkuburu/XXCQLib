// kongyangqing.c 孔扬秦

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("孔扬秦",({"kong yangqin","kong"}));
	set("long",
	"孔扬秦为权力帮出生入死无数次，杀人从不留活口，江湖中人又怕又"
	"恨。\n"
	"他白衣如雪，背插长剑，态度洒若。\n");
	set("party/rank",HIC"三绝剑魔"NOR);
	set("party/party_name","权力帮");
	set("age",44);
	set("gender","男性");
	set("autitude","friendly");
	set("str",28);
	set("con",30);
	set("dex",30);
	set("int",33);
	
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
	carry_object("/clone/weapon/changjian")->wield();

	
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
        if( !arg || arg!="kong" )
                return 0;
        if(wizardp(ob))  return 0;
        if (ob->query("party/party_name") != "权力帮")
        {
                message_vision("$N摇了摇头。\n",this_object());
                command("tell "+ob->query("id")+" 不是权利帮的人不能察看。\n"); 
                return 1;
        }
    command("tell "+ob->query("id")+" 我所有的武功如下：\n"+
"孔扬秦目前所学过的技能：     \n\n"+
"  基本轻功 (dodge)                         - 一代宗师 180/    0  \n"+
"  基本内功 (force)                         - 一代宗师 180/    0   \n"+
"  基本剑法 (sword)                         - 深不可测 200/    0   \n"+
"  基本拳脚 (unarmed)                       - 神乎其技 120/    0 \n");
   return 1;
}
