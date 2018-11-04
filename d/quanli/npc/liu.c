// liu.c
// by mulan

#include <ansi.h>
inherit NPC;
int ask_rank();
int do_skills(string arg);


void create()
{
        set_name("柳随风", ({"liu suifeng", "liu"}));
        set("gender", "男性");
        set("age", 56);
        set("nickname",HIW"袖里日月"NOR);
        set("long",
        "柳随风！ 这一声犹如晴天霹雳，炸响在每个人耳里！ 柳大总管：李沉舟的唯一亲信！\n");
        set("shen_type",1);
        set("str", 32);
        set("int", 30);
        set("con", 30);
        set("dex", 999);

        set("title","“权力帮__军师”");
        set("accept", 6000);

        set("qi", 4000);
        set("max_qi", 4000);
        set("jing", 1600);
        set("max_jing", 1600);
        set("neili", 6000);
        set("max_neili", 6000);
        set("jiali", 100);

        set("combat_exp", 500000);
        set("score", 300000);

        set_skill("force", 200);
        set_skill("sword", 200);
        set_skill("liuxu-shenfa",220);  
        set_skill("dodge", 220);
        set_skill("parry", 200);
        set_skill("literate",180);

        map_skill("dodge", "liuxu-shenfa");
        
        set("inquiry", ([
            "rank" : (: ask_rank :),
            "升级" : (: ask_rank :),            
        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
//	carry_object(__DIR__"obj/grayrobe")->wear();

}

void init()
{
::init();
add_action("do_skills","skills");
add_action("do_skills","cha");
}
int ask_rank()
{
	object me;
	int v_task,i,j,k,h;
	string v_rank,my_rank,str_i,str_j,str_k,str_h;
	string *title1 = ({
"三绝","铁骑","百毒","神拳","铁腕","无影","无名","一洞","长刀","绝灭",
"瘟疫","血影","独脚","千手","快刀","飞腿","暗杀","佛口","飞刀",
});
	string *title2 = ({
"万劫","千恶","红鹜","凌云","克己","飙风","麒麟","不回","金光","高钱",
"火旗","血衣","灵鹰","忘敌","盗文","狞兽","摩天","思丑",
});
	string *title3 = ({
"双翅之一","双翅之二","一杀",
});
	string *title4 = ({
"白凤凰","红凤凰","蓝凤凰",
});
	string *title5 =({
"雪王","山王","力王","志王","灵王","冥王","钧王","擎王",
});
    i = atoi(read_file("/d/quanli/npc/QUANLI_1",1,1));
    j = atoi(read_file("/d/quanli/npc/QUANLI_2",1,1));
    k = atoi(read_file("/d/quanli/npc/QUANLI_3",1,1));
    h = atoi(read_file("/d/quanli/npc/QUANLI_4",1,1));
	
	me = this_player();
	my_rank = me->query("party/rank");
	v_task = (int)me->query("party/tasks");
	
	if(me->query("party/party_name")!="权力帮")
	{
		command("say 你不是权力帮的人，我不能帮你!\n");
		return 1;
	}
	
		
	if(v_task > 10000)
	{
		if(strlen(my_rank)>9 && my_rank[9..10] == "王")
		{
		command("say 你现在不用升级。\n");
		return 1;
		}
        if(h < (sizeof(title5)+1))
		{
        v_rank = HIY""+title5[h]+NOR"";
		h = h+1;
		}
		else
		{
			command("say 护法的席位已经满了!\n");
			return 1;
		}
	}
	else if(v_task > 5000)
	{
		if(strlen(my_rank)>7 && my_rank[7..8] == "柳")
		{
		command("say 你现在不用升级。\n");
		return 1;
		}
		if(me->query("gender") == "男性")
		{
            if(j < (sizeof(title3)+1))
			{
            v_rank = HIW"柳随风手下之"MAG+title3[j]+NOR"";
			j = j+1;
			}
			else
			{
			command("say 亲信的席位已经满了，快去争上一级的吧!\n");
			return 1;
			}
		}
		else
		{
            if(k < (sizeof(title4)+1))
			{
            v_rank = HIW"柳随风手下之"MAG+title4[k]+NOR"";
			k = k+1;
			}
			else
			{
				command("say 亲信的席位已经满了，快去争上一级的吧!\n");
				return 1;
			}
		}
	}
	
	else if(v_task > 2000)
	{
		if(strlen(my_rank)>19 && my_rank[17..20] == "神君")
		{
		command("say 你现在不用升级。\n");
		return 1;
		}			
       if(i < (sizeof(title2)+1))
		{
        v_rank = HIB""+title2[i]+RED" 神君"NOR;
		i = i+1;
		}
		else
		{
			command("say 舵主的席位已经满了，快去争上一级的吧!\n");
			return 1;
		}
	}
	else if(v_task > 1000)
	{
		if(strlen(my_rank)>22 && my_rank[20..23] == "麾下")
		{
		command("say 你现在不用升级。\n");
		return 1;
		}			
		v_rank = RED""+title1[random(sizeof(title1))]+"神君"+HIM"麾下"NOR;
		
	}
	else
	{
	command("say 你对本帮的忠诚度还不够！多做实事吧!\n");
	return 1;
	}
 	if(my_rank[7..8] == "柳" && me->query("gender")=="男性")
 	j = j-1;
 	if(my_rank[7..8] == "柳" && me->query("gender")=="女性")
 	k = k-1;
 	if(my_rank[17..20] == "神君")
 	i = i-1;

	command("chat* gongxi "+me->query("id"));
	command("chat "+me->query("name")+"在权力帮任"+v_rank+"一职。\n");
 	me->set("party/rank",v_rank);
 	
	str_i=sprintf("%d",i);
	str_j=sprintf("%d",j);
	str_k=sprintf("%d",k);
	str_h=sprintf("%d",h);

  if( write_file("/d/quanli/npc/QUANLI",v_rank+"     "+me->query("name")+"\n"))
  command("say 你的记录写入成功!\n");
     else command("say 你的记录写入失败!\n");
    write_file("/d/quanli/npc/QUANLI_1",str_i,1);
    write_file("/d/quanli/npc/QUANLI_2",str_j,1);
    write_file("/d/quanli/npc/QUANLI_3",str_k,1);
    write_file("/d/quanli/npc/QUANLI_4",str_h,1);
	
	return 1;
}

int do_skills(string arg)
{
	object ob ;
	ob = this_player () ;
	if( !arg || arg!="liu" )
		return 0;
	if(wizardp(ob))  return 0;
	if (ob->query("party/party_name") != "权力帮")
	{
		message_vision("$N摇了摇头。\n",this_object());
		command("tell "+ob->query("id")+" 不是权利帮的人不能察看。\n"); 
		return 1;
	}
    command("tell "+ob->query("id")+" 我所有的武功如下：\n"+
"柳随风目前所学过的技能：\n"+

  "基本轻功 (dodge)                         - 深不可测 220/    0	\n"+
  "基本内功 (force)                         - 深不可测 200/    0	\n"+
  "基本招架 (parry)                         - 深不可测 200/    0	\n"+
  "基本剑法 (sword)                         - 深不可测 200/    0	\n"+
  "读书写字 (literate)                      - 初窥门径 180/    0       0/    0	\n"+
"★柳絮身法 (liuxu-shenfa)                  - 半生不熟 220/    0       0/    0	\n");
   return 1;
}
#include "quanli.h"
