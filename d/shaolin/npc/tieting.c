// modify by mulan

inherit NPC;

int ask_book();
int ask_teach();
int do_qingjiao(string arg);


void create()
{

        set_name("铁庭", ({"tie ting","tie","ting",}));
        set("long",
                "他是一位身穿黄布袈裟的青年僧人。脸上稚气未脱，身手却已相\n"
                "当矫捷，看来似乎学过一点武功。\n"
        );

        set("gender", "男性");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 20);
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 35);
        set("dex", 20);
        set("max_qi", 450);
        set("qi", 450);
        set("max_jingli", 400);
        set("jingli", 400);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 20);
        set("combat_exp", 15000);
        
        set_skill("force", 40);
        set_skill("banruo-changong", 40);
        set_skill("dodge", 40);
        set_skill("shaolin-shenfa", 40);
        set_skill("cuff", 50);
        set_skill("luohan-quan", 50);
        set_skill("parry", 40);

        map_skill("force", "banruo-changong");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "luohan-quan");
        map_skill("parry", "luohan-quan");

        prepare_skill("cuff", "luohan-quan");

        create_family("少林派", 37, "弟子");

        set("inquiry", ([
                "study" : (: ask_teach :),
                "听课" : (: ask_teach :),
                "学习" : (: ask_teach :),
                "literate" : (: ask_teach :),
                "book" : (: ask_book :),
                "书" : (: ask_book :),
                "经书" : (: ask_book :),
        ]) );

        setup();

        carry_object(__DIR__"obj/huijiasha")->wear();
        carry_object(__DIR__"obj/sengxie")->wear();
        carry_object("/d/shaolin/obj/jing2");
        carry_object("/d/shaolin/obj/jing3");
        carry_object("/d/shaolin/obj/jing4");
}

void init()
{
        add_action("do_qingjiao", "qingjiao");
}

int ask_book()
{
        object me, *inv, ob;
        mapping myfam, skill;
        int i;
        me = this_player();
        ob = this_object();
        myfam = (mapping)me->query("family");
        inv = all_inventory(ob);

        if (!myfam || myfam["family_name"] != "少林派")
        {
                command("hmm " + me->query("id"));
                command("say 你不是少林弟子，怎么也来要书，还不出去！");
                return 1;
        }

        if (me->query_temp("ask_book", 1))
        {
                command("say 你先前借的书还没还，怎么又来借！");
                return 1;
        }

        for(i=sizeof(inv)-1; i>=0; i--)
        if (inv[i]->query("id") == "jing")
        {
                skill = (mapping)inv[i]->query("skill");
                if (skill["name"] == "buddha")
                {
                        command("give jing to " + me->query("id"));
                        message_vision("铁辉叮嘱道：小心经书，不要丢了或是弄脏了。\n", me);
                        me->set_temp("ask_book", 1);
                        return 1;
                }
        }

        command("say 书已经被其他弟子借光了，你去找他们要要看吧。");

        return 1;
}



int ask_teach()
{
        object me,ob;
        me = this_player();
        ob = this_object();

        if (!me->query("family") || me->query("family/family_name")!="少林派")
        {
                command("say 非少林弟子不得在此读书！");
                return 1;
        }

        if ( me->query_temp("xuet"))
        {
                tell_object(me,"你不是正在学习吗?\n ");
                return 1;
        }

        message_vision("铁庭合十道道："+RANK_D->query_respect(me)+"可是来学习的？\n\n", me);
        command("look "+me->query("id"));

        if ((int)me->query_skill("literate", 1) > 41)
        {
                message_vision("\n铁庭合十道：这位"+RANK_D->query_respect(me)+"颇有学识，在下愧不敢教。\n\n", me);
                return 1;
        }

        else
        {
                message_vision("\n铁庭说：好好，快做好。\n\n", me);
                message_vision("$N走到一个空座前坐了下来。\n\n", me);
                me->apply_condition("xuetang", 10);
                me->set_temp("xuet", 1);
                return 1;
        }
}

 int do_qingjiao(string arg)
{
       object me = this_player();
 	int myexp,daoxue,mypo;

	myexp = (int)me->query("combat_exp");
	daoxue = (int)me->query_skill("buddha",1);
	mypo = (int)me->query("potential");

      if( !arg || !arg = "tie")
          return notify_fail("你向谁请教禅宗佛理？\n");
     
      if( me->query_temp("qinjiao") < 1)
          return notify_fail("你对禅宗佛理的领会还不到家呢!\n");

      command ("say 不错,你已经能领会禅宗心法里的奥秘,还要继续努力\n");
      command ("pat " + me->query("id"));
           me->set("combat_exp",myexp+daoxue+random(20));
//         if ( mypo < (int)me->query("learned_points"))
           me->set("potential",mypo+daoxue/2+random(10));
           me->set_temp("qinjiao",0);
	   me->set_temp("mcount",0);
                 
           return 1;
}
