// Item dashucha.c
// Created by Zeus 1999.5.27
// Modified by Zeus 1999.5.27
// 
// 

inherit ITEM;

void create()
{
        set_name( "大树杈",({ "da shucha"}));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "枝");
                set("long","这是一枝大树杈。\n");
                set("value", 100);
                set("material", "wood");
        }
}
