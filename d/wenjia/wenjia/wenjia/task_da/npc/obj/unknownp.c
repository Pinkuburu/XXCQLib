// Item unknownp.c  不知名毒药
// Created by Zeus 1999.5.27
// Modified by Zeus 1999.5.29
// 
// 

inherit ITEM;

void create()
{
        set_name( "不知名毒药",({ "du yao"}));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long","这是一个小纸包，里面装着一些白色的粉末，怎么看也看不出是什么毒药。\n");
                set("value", 50);
                set("material", "unknown");
        }
}
