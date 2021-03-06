// Item xiangsi.c
// Created by Zeus 1999.4.3
// Modified by Zeus 1999.4.3
// 
// 

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void init()
{
        add_action("do_fang", "diu");
}

void create()
{
        set_name("相思蜂雨中", ({"xiang si"}));

        set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "盒");
                set("long", "这是一个小小的盒子，一点也看不出这是武林人士闻之色变的温家至宝“相思蜂雨中”。\n");
                set("value", 500000);
        }
        init_blade(100);
        setup();
}

int do_fang(string arg)
{
        object me, obj;
        me = this_player();

        if( !arg )
                return notify_fail("你想杀谁？\n");

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("这里没有这个人。\n");
        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");

        if(obj == me)
                return notify_fail("用 suicide 指令会比较快:P。\n");
        message_vision(HIY "\n$N拿起“相思蜂雨中”，向$n放出。 \n\n"NOR, me, obj);

        tell_object(obj, HIR "\n你猛觉浑身如火烧般剧痛，神志迷困，头脑中一片空白！\n" NOR);

        obj->die();
        destruct(this_object());

        return 1;
}
