//Npc:天羽管事
//Write by godzilla 1999.12.22

#include <ansi.h>
inherit NPC;

int ask_me();
int jiangshang2();
void create()
{
        set_name("天羽管事", ({ "guanshi","shi" }));
        set("long",@LONG
他是专门负责对天羽弟子奖赏得管事。\n
LONG
        );
        set("title",HIW"天羽派"NOR);  
        set("gender", "男性");
        set("age", 45);
        set("attitude", "friendly");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 3000);
        set("qi",3000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 100);
        set("combat_exp", 1200000); 
        set("per",20);
        set("max_jingli", 1500);
        set_skill("tianyu-bufa", 100);
        set_skill("literate", 80);
        set_skill("force", 100);
        set_skill("tianyu-qigong", 100);
        set_skill("dodge", 100);
        set_skill("finger", 100);
        set_skill("parry", 100);
        set_skill("sword", 100);
             set_skill("tianyu-qijian",100);
        
        map_skill("force", "tianyu-qigong");
        map_skill("dodge", "tianyu-bufa");
        map_skill("parry", "tianyu-qijian");
        map_skill("sword", "tianyu-qijian");
       
        set("inquiry", ([
                "奖赏" : (: ask_me :),
        ]));
        setup(); 
        carry_object(__DIR__"obj/cloth2")->wear(); 
        carry_object("/clone/weapon/changjian")->wield();
}
int ask_me()
{
        object gold;
        object me=this_player();
        int age,m,gong,i;
        age =(int)me->query("age");
        m=(int)me->query("give_jiang");
        gong=(int)me->query("gongxun");
              
        if (gong >= 200)
        {
              if(me->query("family/family_name")!="天羽派")
              {
                command("say 这为"+ RANK_D->query_respect(me)+"何来向我要奖赏呢?\n");
                return 1;
              }            
              if(m<age)
              {
                i=gong/5;
                if(i>1000)
                i=1000;
                message_vision(CYN"$N掏出一本册子翻了翻，然后对$n说道:不错，你为天羽干了不少事!这是你这一年的奖金！\n"NOR,this_object(),me);
                gold=new("/clone/money/gold");
                gold->set_amount(i);
                gold->move(me);
                message_vision(CYN"$N说完递给了$n"+YEL+chinese_number(i)+CYN+"两黄金。\n"NOR,this_object(),me); 
                me->set("give_jiang",age);
                return jiangshang2();
              }
              command("say 你今年的奖金已经领取了。\n");
              return 1;
        
        }
        else
        {
              if(me->query("family/family_name")!="天羽派")
              {
                command("say 这为"+ RANK_D->query_respect(me)+"何出此问呢?\n");
                return 1;
              }
              command("say 你现在贡献还不够，不能领取奖金。\n");
              return 1;
        }                  
                

}
int jiangshang2()
{
        object ob,me;
        me=this_player();
        if(2>random(3))
        {
                command("say 还好天羽的药房里送来新药，这就一起给你吧!\n");
                ob=new(__DIR__"obj/dan");
                ob->move(me);
                command("say 这个药不到紧要关头不要用，药材配制不易，切记!\n");
                return 1;       
        }
        return 1;
}           
