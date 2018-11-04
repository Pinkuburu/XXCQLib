#include <ansi.h>

inherit ITEM;

void create()
{
   set_name(HIC "碧玉膏" NOR, ({"biyu gao", "gao"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("unit", "包");
        set("long", "这是药王谷精心制作的解毒良药,据说能解血河的剧毒。\n");
       set("value", 35000);
   }
   setup();
}

int init()
{
   add_action("do_eat", "eat");
}

int do_eat(string arg)
{
   object me = this_player();

   if(!id(arg))
       return notify_fail("你要吃什么？\n");

tell_object(this_player(), HIG "你只觉入口后，口干舌燥，吐一口鲜血，感觉好多了。\n" NOR );
   if ((int)me->query_condition("hx_poison") > 0) {
 me->apply_condition("hx_poison", 0);
   }

   destruct(this_object());
   return 1;
}

