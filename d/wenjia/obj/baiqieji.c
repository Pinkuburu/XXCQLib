// Item baiqiuji.c
// Created by Zeus 1999.3.27
// Modified by Zeus 1999.3.27
// 
// 

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("白切鸡", ({"ji","baiqie ji"}));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一碟刚刚出炉的白切鸡，是有温家名厨温吃饭做出来的。你闻到它的香味忍不住流口水。\n");
                set("unit", "碟");
                set("value", 500);
                set("food_remaining", 4);
                set("food_supply", 80);
        }
}
