// /u/bmw/kangchuyu.c 康出渔	

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("康出渔",({"kang chuyu","kang"}));
	set("nickname",HIY"观日神剑"NOR);
	set("title","权力帮"+HIB"无名神魔"NOR);
	set("long",
	"康出渔十三岁开始习剑，二十六岁名动江湖，三十六岁列名天下七大名剑。\n"
	"他身材魁梧，两鬓发白，但目中精光四射，像一把剑一样犀利。\n");
	set("age",51);
    set("accept",2000);
	set("gender","男性");
	set("autitude","friendly");
	set("con",25);
	set("int",28);
	set("dex",26);
	set("str",22);
	set("per",22);
	
	set("max_qi",3000);
	set("max_jing",2000);
	set("neili",3000);
	set("max_neili",3000);
	set("jiali",50);
	
	set("combat_exp",1500000);
	set("score",2000);
	
	set("inquiry",([
		"康劫生":"那是我的犬子。",	
		"权力帮":"我愿为权力帮赴汤蹈火，尽忠尽力！",
		]));
			
	set_skill("dodge",180);
    set_skill("guanri-jian",200);
	set_skill("force",180);
	set_skill("sword",200);
	set_skill("unarmed",120);
	
	setup();
	
    map_skill("sword","guanri-jian");
    map_skill("parry","guanri-jian");
    carry_object("/clone/misc/cloth")->wear();
    carry_object("/clone/weapon/changjian")->wield();
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
        if( !arg || arg!="kang" )
                return 0;
        if(wizardp(ob))  return 0;
        if (ob->query("party/party_name") != "权力帮")
        {
                message_vision("$N摇了摇头。\n",this_object());
                command("tell "+ob->query("id")+" 不是权利帮的人不能察看。\n"); 
                return 1;
        }
    command("tell "+ob->query("id")+" 我所有的武功如下：\n"+
"康出渔目前所学过的技能：   \n\n"+
"  基本轻功 (dodge)                         - 一代宗师 180/    0      \n"+
"  基本内功 (force)                         - 一代宗师 180/    0    \n"+
"  观日剑法 (guanri-jian)                   - 半生不熟 200/    0       0/    0     \n"+
"  基本剑法 (sword)                         - 深不可测 200/    0     \n"+
"  基本拳脚 (unarmed)                       - 神乎其技 120/    0    \n");
   return 1;
}
