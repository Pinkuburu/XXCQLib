// /u/bmw/shaqiandeng.c 沙千灯

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("沙千灯",({"sha qiandeng","sha"}));
	set("nickname",HIW"一刀断魂"NOR);
	set("title","权力帮"+HIB"飞刀神魔"NOR);
	set("long",
	"他就是江湖上人称“天狼噬月，半刀绝命；红灯鬼影，一刀断魂！”的沙千灯。\n"
	"一个提着灯笼的活着的幽灵。据说这盏灯曾使十九名高手迷眩，七位武林高手瞎\n"
	"眼，被他出手一刀，断魂绝命！\n");
	set("age",48);
    set("accept",4800);
	set("gender","男性");
	set("autitude","friendly");
	set("shen_type",1);
	set("con",25);
	set("int",25);
	set("dex",30);
	set("str",20);
	set("per",18);
	
	set("max_qi",3000);
	set("max_jing",2000);
	set("neili",3000);
	set("max_neili",3000);
	set("jiali",50);
	
	set("combat_exp",1300000);
	set("score",2000);
	
//	set("inquiry",([
//		"李沉舟":(: ask_li() :),
//		"赵师容":"哼!你问我大嫂干什么，有什么企图？",
//		"十九人魔":(: ask_renmo() :),
//		"萧西楼":"萧西楼不过是无能之辈，比起他的先祖来差多了。",
//		"权力帮":(: ask_quanli :),
//		"浣花剑派":(: ask_huanhua :),
//		"康劫生":"那是我的犬子。"
//		]));
			
	set_skill("dodge",200);
	set_skill("force",130);
	set_skill("sword",100);
	set_skill("blade",230);
	set_skill("unarmed",120);
	
	create_family("权力帮",2,"帮众");
	
	setup();
	
//    carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/dagger")->wield();

	
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
        if( !arg || arg!="sha" )
                return 0;
        if(wizardp(ob))  return 0;
        if (ob->query("party/party_name") != "权力帮")
        {
                message_vision("$N摇了摇头。\n",this_object());
                command("tell "+ob->query("id")+" 不是权利帮的人不能察看。\n"); 
                return 1;
        }
    command("tell "+ob->query("id")+" 我所有的武功如下：\n"+
"沙千灯目前所学过的技能：   \n\n"+
"  基本刀法 (blade)                         - 深不可测 200/    0      \n"+
"  基本轻功 (dodge)                         - 深不可测 180/    0     \n"+
"  基本内功 (force)                         - 神乎其技 150/    0        \n"+
"  基本拳脚 (unarmed)                       - 神乎其技 120/    0    \n");
   return 1;
}
