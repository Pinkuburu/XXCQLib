// Item facai.c
// Created by Zeus 1999.6.5
// Modified by Zeus 1999.6.5
// 
// 
#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(BLK"发菜肉团"NOR, ({"routuan"}));
        set_weight(400);
        if (clonep()) set_default_object(__FILE__);
        else {
                set("long", "一盘由发菜菜上肉团制成的桂林名菜。\n");
                set("unit", "碟");
                set("value", 500);
                set("food_remaining", 6);
                set("food_supply", 80);
        }
}
