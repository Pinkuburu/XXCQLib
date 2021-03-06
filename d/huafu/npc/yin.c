// yin.c 银盛雪

#include <ansi.h>

#include "/d/huafu/npc/cam.h"
inherit NPC;
inherit F_MASTER;
#include "/d/huafu/npc/yin.h"

int ask_kungfu();
void heal_ob();
void recover_ob();
void create()
{
	set_name("银盛雪", ({ "yin shengxue", "yin" }));
	set("nickname",HIW"破山刀客"NOR);
         set("rank","党羽");
	set("gender", "男性");
	set("age", 33);

        set("combat_exp", 800000);
          set("max_neili",3000);
          set("neili",3000);
          set("max_qi",3000);
          set("eff_qi",3000);
          set("qi",3000);
          set("max_jingli",3000);
          set("eff_jingli",3000);
          set("jingli",3000);
        set_skill("cuff",50 );
        set_skill("confu",150);
        set_skill("force",150);
        set_skill("dodge",150);
          set_skill("poshan-dao",350);
               set_skill("blade",350);
        set_skill("banruo-changong",150);
        
        map_skill("force","banruo-changong");
	map_skill("blade","poshan-dao");
       create_party(HIG"发梦二党"NOR,HIR"总教头"NOR,5);
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/huafu/npc/obj/poshan-dao")->wield();
          set("inquiry",([
                    "破山刀法" : (: ask_kungfu :),
                    "学艺" : (: ask_kungfu1 :),
                    "blade" : (: ask_kungfu2 :),
                    "刀法" : (: ask_kungfu2 :),
                    "绝招" : (: ask_kungfu :),
          ]));
          set("chat_chance",2);
          set("chat_msg",({
                 (: recover_ob :),
          }));
          set("chat_chance_combat",30);
          set("chat_msg_combat",({
                (: perform_action,"blade.shipo" :),
                (: recover_ob :),
          }));
}

void heal_ob()
{
        command("yun heal");
        return;
}

void recover_ob()
{
        command("yun recover");
        return;
}

void attempt_join()
{
        object ob;
        object mee;
        
        ob = this_player () ;
        mee=this_object();
        if ((int)ob->query("shen") < 0)
        {
        message_vision(HIC "$n对$N大怒道：一看你就不是好人!\n" NOR,ob,mee);
//      set_leader(this_player());
        remove_call_out("kill_ob");
        call_out("kill_ob", 1, this_player()); 
        return;
        }
        if ((int)ob->query("shen") < 1000)
        {
        message_vision(HIC "$N摇摇头道：你还不够侠义!\n" NOR,mee);
        return;
        }
        if (ob->query("combat_exp")<10000)
        {
        message_vision(HIC "$n对$N摇头道：你的实战经验太低。\n" NOR,ob,mee);
        return;
        }
                command("smile");
                command("handshake "+this_player()->query("id"));
                command("nodjoin "+this_player()->query("id"));
                command("tell "+this_player()->query("id")+" 大家从此就是一家人了。\n");
        return;
}

