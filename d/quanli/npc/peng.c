// pengjiu.c ����	

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("����",({"peng jiu","peng"}));
	set("long",
	"�������괳������ʱ���˿�ȥһ�ţ�ȴΪ�˿������ţ��Ը�����ţ�\n"
	"���������ɾ͡�\n"
	"������������������֣�Ψ�ж���ʹ���������ۡ�\n");
	set("party/rank",HIC"������ħ"NOR);
	set("party/party_name","Ȩ����");
	set("nickname",HIG"������ǧɽ"NOR);
	set("age",44);
	set("gender","����");
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
		"Ȩ����":"��ԸΪȨ���︰�����𣬾��Ҿ�����",
		]));
			
    set_skill("dodge",150);
    set_skill("force",150);
    set_skill("staff",200);
    set_skill("leg",180);
	
	setup();
	
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangzhang")->wield();
	
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
        if( !arg || arg!="peng" )
                return 0;
        if(wizardp(ob))  return 0;
        if (ob->query("party/party_name") != "Ȩ����")
        {
                message_vision("$Nҡ��ҡͷ��\n",this_object());
                command("tell "+ob->query("id")+" ����Ȩ������˲��ܲ쿴��\n"); 
                return 1;
        }
    command("tell "+ob->query("id")+" �����е��书���£�\n"+
"�� ����Ŀǰ��ѧ���ļ��ܣ�    \n"+
"\n  �����Ṧ (dodge)                         - �����뻯 150/    0     \n"+
"  �����ڹ� (force)                         - �����뻯 150/    0    \n"+
"  �����ȷ� (staff)                         - ��ɲ� 200/    0   \n"+
"  �����ȷ� (leg)                           - ��ͨƤë 180/    0       0/    0    \n");
   return 1;
}