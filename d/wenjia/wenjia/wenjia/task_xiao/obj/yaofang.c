// Item yaofang.c  
// Created by Zeus 1999.7.30
// Modified by Zeus 1999.7.30
// 
// 

inherit ITEM;

void create()
{
        set_name( "药方",({ "yao fang"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long","这是一张药方。\n");
                set("value", 100);
                set("material", "paper");
        }
}
