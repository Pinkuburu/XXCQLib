// yanguigui.c 阎鬼鬼

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("阎鬼鬼",({"yan guigui","yan"}));
	set("long",
	"阎鬼鬼辖管权力帮贵州分帮，手下有六名弟子，功夫各异，权力帮的\n"
	"一名得力手下。\n"
	"他骑在一匹高大的黑马上，手中握着一条长鞭，目光如炬。\n");
	set("party/rank",HIC"铁骑神魔"NOR);
    set("accept",2000);
	set("party/party_name","权力帮");
	set("age",47);
	set("gender","男性");
	set("autitude","friendly");
	set("str",29);
	set("con",25);
	set("dex",22);
	set("int",24);
	
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
    set_skill("whip",200);
    set_skill("parry",150);
	
	setup();
	
	carry_object("/clone/misc/cloth")->wear();
    carry_object("/clone/weapon/changbian")->wield();

	
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
        if( !arg || arg!="yan" )
                return 0;
        if(wizardp(ob))  return 0;
        if (ob->query("party/party_name") != "权力帮")
        {
                message_vision("$N摇了摇头。\n",this_object());
                command("tell "+ob->query("id")+" 不是权利帮的人不能察看。\n"); 
                return 1;
        }
    command("tell "+ob->query("id")+" 我所有的武功如下：\n"+
"※ 阎鬼鬼目前所学过的技能：     \n"+
"\n  基本轻功 (dodge)                         - 出神入化 150/    0    \n"+
"  基本内功 (force)                         - 出神入化 150/    0    \n"+
"  基本招架 (parry)                         - 出神入化 150/    0     \n"+
"  基本鞭法 (whip)                          - 深不可测 200/    0    \n");
   return 1;
}
