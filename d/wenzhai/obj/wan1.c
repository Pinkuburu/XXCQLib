// wan.c

inherit ITEM;
#include <ansi.h>

void create()
{
         set_name("药丸",({"wan"}));
        if ( clonep() )
             set_default_object(__FILE__);
        else
        {
         set("long","*******\n");
         set("value",1);
         set("unit","颗");
         setup();
        }
}

void init()
{
      add_action("do_eat","eat");
}

int do_eat(string arg)
{
      object me;
      me=this_player();

      if (arg!="wan") return 0;
/*
         if (me->query_skills())
         {
        sk = keys(me->query_skills());                  // 所学武功的名称集合
        for(i = 0; i<sizeof(sk); i++)
        {
           me->set_skill(sk[i],me->query_skill(sk[i],1)+1);

        }
      }

         me->set("combat_exp",me->query("combat_exp")*102/100);
          me->set("protential",me->query("protential")*2);
        me->set_skill("jieniu-dao",50);
        me->set_skill("cuff",50);
        me->set_skill("huaxue-dafa",50);
        me->set_skill("yiqiguan-riyue",50);
        me->set_skill("feixue-quan",50);
        me->set_skill("youran-bu",50);
        me->set_skill("force",50);
        me->set_skill("dodge",50);
        me->set_skill("parry",50);
        me->set_skill("blade",50);
        me->set_skill("tao",50);
*/
            me->add("max_neili",100);
            me->add("max_jingli",100);
            me->set_skill("longmen-shengong",209,168);
            me->set_skill("literate",181,0);
       destruct(this_object());
}
