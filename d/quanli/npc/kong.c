// kongyangqing.c ������

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("������",({"kong yangqin","kong"}));
	set("long",
	"������ΪȨ����������������Σ�ɱ�˴Ӳ�����ڣ���������������"
	"�ޡ�\n"
	"��������ѩ�����峤����̬��������\n");
	set("party/rank",HIC"������ħ"NOR);
	set("party/party_name","Ȩ����");
	set("age",44);
	set("gender","����");
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
		"Ȩ����":"��ԸΪȨ���︰�����𣬾��Ҿ�����",
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
        if (ob->query("party/party_name") != "Ȩ����")
        {
                message_vision("$Nҡ��ҡͷ��\n",this_object());
                command("tell "+ob->query("id")+" ����Ȩ������˲��ܲ쿴��\n"); 
                return 1;
        }
    command("tell "+ob->query("id")+" �����е��书���£�\n"+
"������Ŀǰ��ѧ���ļ��ܣ�     \n\n"+
"  �����Ṧ (dodge)                         - һ����ʦ 180/    0  \n"+
"  �����ڹ� (force)                         - һ����ʦ 180/    0   \n"+
"  �������� (sword)                         - ��ɲ� 200/    0   \n"+
"  ����ȭ�� (unarmed)                       - ����似 120/    0 \n");
   return 1;
}