inherit ITEM;
#include <ansi.h>

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
	set_name(HIG "仙豆" NOR, ({"dou"}));
        set("unit", "粒");
	set("long", "这是一颗千金难得的仙豆，是加林仙人花一年时间才能种出来的，据说\n一颗就可以恢复全部的精神，治愈所有的伤处。\n");
        setup();
}

int do_eat(string arg)
{
if (!id(arg))  return notify_fail("你要吃什么？\n");
if(arg=="dou") 
{
tell_object(this_player(), HIG "你只觉一股清香沁入心肺，顿时所有的伤口都复原了，而且神采飞扬，神意清爽！\n" NOR );
this_player()->set_temp("nopoison", 1);
this_player()->set("jingli",this_player()->query("max_jingli"));
this_player()->set("eff_qi",this_player()->query("max_qi"));
this_player()->set("qi",this_player()->query("max_qi"));
this_player()->set("neili",this_player()->query("max_neili"));
destruct(this_object());
}
return 1;
}
