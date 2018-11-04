// Item mifen.c
// Created by Zeus 1999.6.5
// Modified by Zeus 1999.6.5
// 
// 
#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(BLU"桂林马肉米粉"NOR, ({"mifen"}));
        set_weight(400);
        if (clonep()) set_default_object(__FILE__);
        else {
                set("long", "一碗由秘方制作的马肉米粉，著名的桂林风味小吃。\n");
                set("unit", "碗");
                set("value", 300);
                set("food_remaining", 4);
                set("food_supply", 80);
        }
}
