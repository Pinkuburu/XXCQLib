// bukuai.c 
// god
#include <ansi.h>
inherit NPC;


void create()
{
        set_name("捕快", ({ "bukuai" }));
        set("title", "心狠手辣");
        set("gender", "男性");
        set("age", 43);
        set("str", 20);
        set("dex", 20);
        set("long", "他是朝廷钦命的捕快。\n");
        set("combat_exp", 30000);
        set("shen_type", 0);
        set("attitude", "heroism");

        set_skill("unarmed", 50);
        set_skill("force", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_temp("apply/attack", 150);
        set_temp("apply/defense", 150);
        set_temp("apply/armor", 150);
        set_temp("apply/damage", 150);

        set("neili", 500); 
        set("max_neili", 500);
        set("jiali", 10);

        setup();
        carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        ::init();
        add_action("do_chat", "chat");
        add_action("do_chat","chat*");
        add_action("do_rumor","rumor");
        add_action("do_rumor","rumor*");
        add_action("do_new","new");
        add_action("do_new","new*");
        add_action("do_party","party");
        add_action("do_party","party*");
        add_action("do_es","es");
        add_action("do_es","es*");
}
int do_chat()
{
   object ob;
   ob=this_player(1);
  
   say(HIW "捕快脸色一沉，喝道：“监狱里，竟敢喧哗！”\n" NOR);
   tell_object(ob, HIR "两边狱头冲上前来，不由分说，一阵大板打得你"
                  +"皮开肉绽,昏了过去。\n" NOR);
   ob->unconcious();
   return 1;
}
int do_rumor()
{
   object ob;
   ob=this_player(1);
  
   say(HIW "“捕快脸色一沉，喝道：“监狱里，竟敢喧哗！”\n" NOR);
   tell_object(ob, HIR "两边狱头冲上前来，不由分说，一阵大板打得你"
                  +"皮开肉绽,昏了过去。\n" NOR);
   ob->unconcious();
   return 1;
}
int do_party()
{
   object ob;
   ob=this_player(1);
  
   say(HIW "捕快脸色一沉，喝道：“监狱里，竟敢喧哗！”\n" NOR);
   tell_object(ob, HIR "两边狱头冲上前来，不由分说，一阵大板打得你"
                  +"皮开肉绽,昏了过去。\n" NOR);
   ob->unconcious();
   return 1;
}
int do_new()
{
   object ob;
   ob=this_player(1);
  
   say(HIW "捕快脸色一沉，喝道：“监狱里，竟敢喧哗！”\n" NOR);
   tell_object(ob, HIR "两边狱头冲上前来，不由分说，一阵大板打得你"
                  +"皮开肉绽,昏了过去。\n" NOR);
   ob->unconcious();
   return 1;
}
int do_es()
{
   object ob;
   ob=this_player(1);
  
   say(HIW "捕快脸色一沉，喝道：“监狱里，竟敢喧哗！”\n" NOR);
   tell_object(ob, HIR "两边狱头冲上前来，不由分说，一阵大板打得你"
                  +"皮开肉绽,昏了过去。\n" NOR);
   ob->unconcious();
   return 1;
}


