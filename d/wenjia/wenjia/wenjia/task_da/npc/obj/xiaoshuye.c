// Item xiao shuye.c
// Created by Zeus 1999.5.27
// Modified by Zeus 1999.5.27
// 
// 

inherit ITEM;

void create()
{
        set_name( "小树叶",({ "xiao shuye"}));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "片");
                set("long","这是一片小树叶。\n");
                set("value", 50);
                set("material", "wood");
        }
}
