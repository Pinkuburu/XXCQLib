// fojing11.c

#include <ansi.h>
inherit ITEM;

void init()
{
        add_action("do_discuss","discuss");
}


string* titles = ({
        "维摩经",
        "法华经",
        "华严经",
        "无量寿经",
        "大般涅磐经",
        "阿含经",
        "波罗蜜多心经",
});

void create()
{
       set_name(YEL + titles[random(sizeof(titles))] + NOR, ({ "jing", "shu", "book" }));
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "本");
                set("long", "这是一册佛经，书页已经泛黄，里面记载了一些初级的禅宗思想。\n");
//        set("value", 1000);�)
                set("material", "paper");
                set("skill", ([
                        "name": "buddha",
                        "exp_required" : 0,
                        "jingli_cost" : 20,
                        "difficulty" : 10,
                        "min_skill" : 0,
                        "max_skill" : 40,
                ]));
        }
}
int do_discuss(string arg)
{
    object me, obj,ob;
    int mylev , objlev ,myexp,objexp;
    int myint , objint,count,times;

    string book_name = "jing";
    mapping skill = this_object()->query("skill");
      mapping fam;
    me = this_player();
      fam = me->query("family");
       
        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");     
         
        if( environment(me)->query("no_fight") )
                return notify_fail("这里不要讨论。\n");

        if( !arg )
                return notify_fail("你想和谁研讨佛经？\n");
       if (!(fam = me->query("family")) || fam["family_name"] != "少林派")
      return notify_fail("你不是佛门弟子,如何使得!\n");

        if(!objectp(obj = present(arg, environment(me))))

                return notify_fail("这里没有这个人。\n");

        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");

        if(obj == me)
                return notify_fail("你不能自学的。\n");

        myexp =  me -> query ("combat_exp" ) ;
        objexp = obj -> query ("combat_exp" ) ;
        mylev =  (int)me -> query_skill("buddha",1) ;
        objlev = (int)obj -> query_skill("buddha",1) ;
        myint = (int) me -> query("int" ) ;
        objint = (int)obj -> query("int" ) ;
        times = (int)me->query("MKS")/10+(int)me->query("PKS")/5+random(5)+5;

        if ((int)me->query("shen") < 0  || (int)obj->query("shen") < 0)
                      return notify_fail("佛经是正派人士研讨之用的\n");

        if(!objectp(ob = present(book_name, obj)) )
                return notify_fail("对方没有佛经怎么研讨啊!\n");

        if ( (mylev < 20) || (mylev > (skill["max_skill"]+1)*2))
                return notify_fail("你的禅宗心法太低 或 这本佛经太浅了!\n");

        if ( (objlev < 20) || (objlev > (skill["max_skill"]+1)*2))
                            return notify_fail("对方的禅宗心法太低 或 那本佛经太浅了!\n");
                         if ( (mylev - objlev)*100/objlev > 20 || (objlev - mylev)*100/mylev > 20) 
		 	 return notify_fail("你们的禅宗心法差距太大了,不能共同研讨!\n");

		 if ( (me->query("int") - obj->query("int")) > 10 || (obj->query("int") - me->query("int")) > 10)
				 return notify_fail("你们的天资差距太大了,不能共同研讨!\n");
          if ( me->query("jingli") < 20 || me->query("qi") < 20 || obj->query("qi") < 20 || obj->query("jingli") <20)
				 return notify_fail("你们的气血已经不能再研讨了!\n");



                         if (me->query_temp("qinjiao") > 0)
				 return notify_fail("你对禅宗心法的理解需要高人的指引!\n");

              if (me->query_temp("mcount") > times )  {
                            me->set_temp("qinjiao",1);
                       obj->set_temp("qinjiao",1);
                            return notify_fail("你们双方都领会了禅宗心法新的要领了!\n");}

              message_vision(HIY "\n$N翻开佛经和$n一起参悟其中的奥秘.\n"NOR, me, obj);
              count = me->query_temp("mcount");
//                         score = me->query("score");
             me->set_temp("mcount",count+1);
//               if (times < 20)  me->set("score",score+100-times*5);
//                        else me->set("score",score+100-times*3);

          me->improve_skill("buddha", (int)me->query_skill("literate", 1)/5+5);
          obj->improve_skill("buddha", (int)obj->query_skill("literate", 1)/5+5);
         me -> receive_damage ("jingli", 30 - random(5));
         me -> receive_damage ("qi", 30 -  random(5));
         obj -> receive_damage ("jingli", 30 - random(5));
         obj -> receive_damage ("qi",30 - random(5));
	 obj -> start_busy (1) ;
         me -> start_busy (1) ;
         return 1;
}
