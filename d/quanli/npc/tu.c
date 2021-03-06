 // tugun.c 屠滚

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("屠滚",({"tu gun","tu"}));
	set("long",
	"屠滚外号“暗器三十六手，暗桩三十六路”，善使暗器与布阵，杀人\n"
	"于无形，后投靠权力帮。\n"
	"他肥肥的身躯裹着一件黄衫，两小眼不时地瞟来瞟去。\n");
	set("party/rank",HIC"千手神魔"NOR);
	set("party/party_name","权力帮");
	set("age",42);
	set("gender","男性");
	set("autitude","friendly");
	set("str",25);
	set("con",26);
	set("dex",32);
	set("int",28);
	
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
    set_skill("throwing",200);
    set_skill("parry",150);
	
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
        if( !arg || arg!="tu" )
                return 0;
        if(wizardp(ob))  return 0;
        if (ob->query("party/party_name") != "权力帮")
        {
                message_vision("$N摇了摇头。\n",this_object());
                command("tell "+ob->query("id")+" 不是权利帮的人不能察看。\n"); 
                return 1;
        }
    command("tell "+ob->query("id")+" 我所有的武功如下：\n"+
"屠滚目前所学过的技能：   \n"+
"\n  基本轻功 (dodge)                         - 出神入化 150/    0     \n"+
"  基本内功 (force)                         - 出神入化 150/    0     \n"+
"  基本招架 (parry)                         - 出神入化 150/    0     \n"+
"  基本暗器 (throwing)                      - 深不可测 200/    0    \n");
   return 1;
}
