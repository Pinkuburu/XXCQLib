// Item yaocai.c
// Created by Zeus 1999.3.28
// Modified by M.A.D. 1999.7.19
// 
// 

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name("药材", ({"yao", "yaocai"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "包");
                set("long", "这是一包自制的可以治伤的药。\n");
                set("value", 5000);
        }
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
                return notify_fail("你要吃什么药？\n");
                if ((int)this_player()->query("eff_jingli") == 
                    (int)this_player()->query("max_jingli"))
                return notify_fail("你现在很健康，不需要用药材。\n");
        else {
                this_player()->receive_curing("jingli", 100);
                message_vision("$N吃下一包药材，精神看起来好多了。\n", this_player());
                destruct(this_object());
                return 1;
        }
}
