// waiter.c

inherit NPC;

void create()
{
               int value;
                    value = random(10);
            set("combat_exp", 1500 + 5 * value);
         set_name("妇女", ({ "woman" }));
           set("gender", "女性");
     set("long", "一个寻常的妇人.");
       set("max_qi",120);
    set("age", 24);
        set("attitude", "peaceful");
          set("str", 24);
        set("dex", 16);
        set("shen", 100);
        set_skill("dodge", 20);
          set("cuff", 20);
        set_skill("parry", 20);
        set_skill("force", 20);

        set("chat_msg", ({
                     "妇人左顾右盼，似乎在找她的孩子。”\n",
        }));

         setup();
          carry_object("/clone/misc/cloth")->wear();
            add_money("silver", 15 + value);
}
