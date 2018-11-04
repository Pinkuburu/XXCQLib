// qi.c 戚恋霞


inherit NPC;
inherit F_MASTER;
#include <ansi.h>
#include "/kungfu/class/fameng/sandai.h"

int ask_quit( );
void create()
{
	set_name("戚恋霞", ({ "qi lianxia", "qi" }));
	set("nickname",HIR"今宵多珍重"NOR);
         set("rank","党羽");
	set("gender", "女性");
	set("age", 23);

        set("combat_exp", 300000);
          set_skill("tao",80);
          set_skill("parry",80);
          set_skill("cuff",80);
          set_skill("force",80);
          set_skill("dodge",80);
          set_skill("bairen-shengong",80);
          set_skill("fengye-xiangsi",80);
          set_skill("yiye-zhiqiu",80);
        
        map_skill("force","bairen-shengong");
          map_skill("dodge","fengye-xiangsi");
          map_skill("cuff","yiye-zhiqiu");
          map_skill("parry","yiye-zhiqiu");

          prepare_skill("cuff","yiye-zhiqiu");
	
        create_party(HIG"发梦二党"NOR,HIM"护院"NOR,2);
        create_family("发梦二党",3,"弟子");
        set("inquiry", ([
                "退出" : (: ask_quit :),
                "quit" : (: ask_quit :),
        ]) );
	setup();
        set("chat_chance",1);
	set("chat_msg",({
                "戚恋霞说道：只要是为国为民的正义之士，都可以加入我们发梦二党。\n",
                "戚恋霞说道：大首领的寿辰就要到了，这几天鱼龙混杂。我要好好盯着。\n",
	}));
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
/*
	object ob;
       object *obb;
       mapping fam,party;
       mapping myfam,myparty;
       int i;
      object me=this_player();
	if( interactive(me) && me->query_temp("killwei") && (file_name(environment(me))=="/d/huafu/menfang") ) {
       fam=(mapping)me->query("family");
       party=(mapping)me->query("party");
        message_vision(HIG"突然，路边的树林嗖的飞出一枚响箭。\n"NOR,me);
       obb=users();
	for(i=0; i<sizeof(obb); i++) {
	myfam=(mapping)obb[i]->query("family");
	myparty=(mapping)obb[i]->query("party");
	if ((myfam && myfam["family_name"]=="发梦二党") || (myparty && myparty["party_name"]==HIG"发梦二党"NOR) )
      {
       if (fam)
       {
                tell_object(obb[i],HIC"发梦二党正遭"+fam["family_name"]+"派袭击，弟子们速回本帮镇守。\n"NOR);
         }
        if (party)
         {
                tell_object(obb[i],HIC"发梦二党正遭"+party["party_name"]+"帮众袭击，弟子们速回本帮镇守。\n"NOR);
         }
         obb[i]->set_temp("compaign_start",1);
        }
      }
        message_vision("紧接着，又窜出三条黑影向你扑来。\n",me);
        ob=new("/d/huafu/npc/menwei");
        ob->move(environment(me));
        ob->kill_ob(me);
        me->kill_ob(ob);
        ob=new("/d/huafu/npc/menwei");
        ob->move(environment(me));
        ob->kill_ob(me);
        me->kill_ob(ob);
        ob=new("/d/huafu/npc/menwei");
        ob->move(environment(me));
        ob->kill_ob(me);
        me->kill_ob(ob);
        message_vision(HIC "戚恋霞道：你们先顶住，我去报告!\n" NOR,this_player());
        this_object()->move("/d/huafu/dongxiangfang");
      if (objectp(ob=present("tang yidu",environment(this_object()))));
      ob->move("/d/huafu/dating");
        this_object()->move("/d/huafu/dongting");
      if (objectp(ob=present("yin shengxue",environment(this_object()))));
      ob->move("/d/huafu/dating");
        this_object()->move("/d/huafu/neitang");
      if (objectp(ob=present("hua kufa",environment(this_object()))));
      ob->move("/d/huafu/dating");
        this_object()->move("/d/huafu/xixiangfang");
      if (objectp(ob=present("song zhanmei",environment(this_object()))));
      ob->move("/d/huafu/dating");
        this_object()->move("/d/wenzhai/sxge");
      if (objectp(ob=present("qing moushi",environment(this_object()))));
      ob->move("/d/huafu/dating");
        this_object()->move("/d/wenzhai/damen");
      if (objectp(ob=present("long tuzhu",environment(this_object()))));
      ob->move("/d/huafu/dating");
        this_object()->move("/d/wenzhai/neitang");
      if (objectp(ob=present("wen mengcheng",environment(this_object()))));
      ob->move("/d/huafu/dating");
        this_object()->move("/d/wenzhai/xixiangfang");
      if (objectp(ob=present("luo wuxia",environment(this_object()))));
      ob->move("/d/huafu/dating");
       this_object()->move("/d/huafu/dating");
        }
*/

}

void attempt_join()
{
        object ob;
        object mee;
        
        ob = this_player () ;
        mee=this_object();
        if ((int)ob->query("shen") < 0)
        {
        message_vision(HIC "戚恋霞对$N大怒道：一看你就不是好人!\n" NOR,this_player());
//      set_leader(this_player());
        remove_call_out("kill_ob");
        call_out("kill_ob", 1, this_player()); 
        return;
        }
        if(ob->query("party"))
        {
        command("say 你已经加入其他帮派了，我怎能收你!\n");
        return;
        }
        if ((int)ob->query("shen") < 1000)
        {
        message_vision(HIC "戚恋霞摇摇头道：你还不够侠义!\n" NOR,this_player());
        return;
        }
        if (ob->query("combat_exp")<10000)
        {
        message_vision(HIC "戚恋霞对$N摇头道：你的实战经验太低。\n" NOR,this_player());
        return;
        }
                command("smile");
                command("handshake "+this_player()->query("id"));
                command("nodjoin "+this_player()->query("id"));
                command("tell "+this_player()->query("id")+" 大家从此就是一家人了。\n");
        return;
}
     int ask_quit( )
    {
     if (this_player()->query("party/party_name")==HIG"发梦二党"NOR)
       {
        command("dao");
        command("heng "+this_player()->query("id"));
        this_player()->delete("party");
        return 1;
        }
        else 
          { command("say 你不是发梦的你问什么啊?\n");
          command("say 你是"+this_player()->query("party/party_name")+",问这个干什么啊?\n");
          return 1;
        }
     }
