// waiter.c

inherit NPC;

void create()
{
               int value;
                    value = random(10);
                 set("combat_exp", 1500 + 5*value);
         set_name("游客", ({ "you ke" }));
    set("age", 24);
        set("gender", "男性");
          set("long", "这是一位来汴梁观光的外地游客，风尘朴朴。");
        set("attitude", "peaceful");
          set("str", 24);
         set("max_qi", 300);
        set("dex", 16);
         set("shen", 1000);
        set_skill("cuff", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("force", 20);

        set("chat_msg", ({
                      "游客说到汴梁果然气势宏伟，比起家乡要好多了。”\n",
        }));

         setup();
                  carry_object("/clone/misc/cloth")->wear();
              add_money("silve", 10 + value);
}
