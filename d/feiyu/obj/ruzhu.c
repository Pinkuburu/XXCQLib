// Item baiqiuji.c
// Created by Zeus 1999.3.27
// Modified by Zeus 1999.3.27
// 
// 

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("乳猪", ({"zhu","ru zhu"}));
        set_weight(40);
        if (clonep())
	set_default_object(__FILE__);
        else {
                set("long", "一只烤得发红的乳猪，味道一流。\n");
                set("unit", "碟");
                set("value", 500);
                set("food_remaining", 4);
                set("food_supply", 80);
        }
}
