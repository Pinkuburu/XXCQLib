// Item shuiyu.c
// Created by Zeus 1999.6.5
// Modified by Zeus 1999.6.5
// 
// 
#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(YEL"黄焖水鱼"NOR, ({"shuiyu"}));
        set_weight(400);
        if (clonep()) set_default_object(__FILE__);
        else {
                set("long", "一盘由秘方焖制的桂林风味名菜。\n");
                set("unit", "碟");
                set("value", 600);
                set("food_remaining", 7);
                set("food_supply", 80);
        }
}
