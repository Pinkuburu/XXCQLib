// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void heal_ob();
void recover_ob();
int ask_jian();

void create()
{
        set_name("孙慧珊", ({"sun huishan", "sun", "huishan"}));
        set("gender", "女性");
        set("title", "浣花剑派"HIM"掌门夫人"NOR);
        set("age", 54);
        set("long", 
"她是“十字慧剑”老掌门人孙天庭的独生女儿，也是浣花剑派现任掌门夫人。\n"
"她的武艺人品均称一流，浣花剑派今天的兴旺绝对有她的一份功劳。\n");
        set("attitude", "peaceful");
        set("str", 15);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("bac", 25);

        set("qi", 2900);
        set("max_qi", 2900);
        set("jingli", 2100);
        set("max_jingli", 2100);
        set("neili", 2400);
        set("max_neili", 2400);
        set("jiali", 25);
        
        set("combat_exp", 1200000);
        set("shen", 10000);
        
        set_skill("force", 170);
        set_skill("jiuqu-xinfa", 170); 
        set_skill("strike", 180);
        set_skill("dodge", 180); 
        set_skill("huanhua-shenfa", 180); 
        set_skill("sword", 210); 
        set_skill("parry", 180); 
        set_skill("literate", 150); 
        set_skill("confu", 150); 
        
        map_skill("force", "jiuqu-xinfa");
        map_skill("dodge", "huanhua-shenfa");

        create_family("十字剑派", 3, "弟子");
        set("inquiry", ([
                "萧西楼" : "他是我的夫君!",
                "浣花神箭" : (:ask_jian:),
        ]) );

        setup();

        carry_object("/d/huanhua/npc/obj/changqun")->wear();
        carry_object("/clone/weapon/changjian");

        set("chat_chance", 3);
        set("chat_msg", ({
                (: heal_ob :),
                "萧夫人担心的张望着：秋水都离家好久了，怎么也没有个信呢？\n",
                "萧夫人不安的辗转：“老夫人不要有事才好，可是权力帮的攻势越来越紧，怎么办好呢？”\n",
        }));

        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: recover_ob :)
        }) );
}

void heal_ob()
{
        command("yun heal");
        command("yun heal");
        command("yun heal");
        command("yun recover");
        command("unwield jian");
        return;
}

void recover_ob()
{
        command("yun recover");
        command("wield jian");
        return;
}

void attempt_apprentice(object ob)
{
        command("say 我的武功放手太久了，生疏了，怎敢谈收徒呢？");
        command("blush");
        return;
}
int ask_jian()
{
      object ob;
      object me = this_player();
      mapping fam;
      fam = me->query("family");
      if ( fam["family_name"] != "浣花剑派")
      return 0;
      if(me->query("combat_exp")< 100000) {
      command("say 你的经验还不够,用浣花神箭也没有什么意义!\n");
      return 1;
    }
      if(present("shen jian",me))
      {  
        command("say 你不是已经有了吗?\n");
          return 1;
      }
      ob = new("/d/huanhua/npc/obj/shenjian");
      ob->move(me);
      command("ok");
      command("say 切记: 紧急时方能使用!\n");
      return 1;
}

