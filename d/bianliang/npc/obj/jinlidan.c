// jinchuang.c 金创药

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
              add_action("do_eat", "eat");
}

void create()
{
          set_name(HIY"醒神丸"NOR, ({"xingshen wan", "wan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
        set("unit", "颗");
      set("long", "这是一颗略带清香的药丸。\n");
             set("value", 4000);
	}
	setup();
}

   int do_eat(string arg)
{
	if (!id(arg))
             return notify_fail("你要吃什么药？\n");
           if ((int)this_player()->query("eff_jingli") == 
              (int)this_player()->query("max_jingli"))
             return notify_fail("你现在不需要吃醒神丸。\n");
	else {
            this_player()->receive_curing("jingli", 50);
           message_vision("$N吃下一颗醒神丸,觉得神志清醒了一些。\n", this_player());
		destruct(this_object());
		return 1;
	}
}
