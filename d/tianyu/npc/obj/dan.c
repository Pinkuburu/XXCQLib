// dan.c
//Write by godzilla

inherit ITEM;
#include <ansi.h>

void create()
{
        string *name=({HIY"金风丸"NOR,HIC"玉露丸"NOR,YEL"大还丹"NOR,HIW"回心散"NOR,MAG"铁心丹"NOR,RED"蝮蛇膏"NOR});
        set_name(name[random(sizeof(name))], ({"dan","wan"}));
        set("unit", "个");
        set("long", "这是由天羽药房提供的丹药可以服用(fu)。\n");
        setup();
}
void init()
{
        add_action("do_eat", "fu");
}

int do_eat(string arg)
{
        if (!id(arg))
        return notify_fail("你要服用什么？\n");
        if(arg=="dan"||arg=="wan")
        {
                tell_object(environment(this_player()),HIR+this_player()->name()+"服下了一个不起眼的丹丸\n"NOR);
                tell_object(this_player(), HIG "你只觉一股内力从丹田涌出，说不出的舒服。\n" NOR);
                this_player()->set("eff_jing",this_player()->query("max_jing"));
                this_player()->set("jing",this_player()->query("max_jing"));
                this_player()->set("eff_qi",this_player()->query("max_qi"));
                this_player()->set("qi",this_player()->query("max_qi"));
                this_player()->set("douzhi",this_player()->query("max_douzhi"));
                this_player()->set("neili",this_player()->query("max_neili")*2);
                destruct(this_object());
        }
        return 1;
}

