// Item gubo.c
// Created by Zeus 1999.5.11
// Modified by Zeus 1999.5.11
// 
// 

inherit ITEM;

void create()
{
        set_name("古钹",({"gubo"}));
        set_weight(50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一个古钹，也不知道有什么用。\n");
                set("unit", "个");
                set("value", 1000);
                set("remaining", 5);
        }
	
        setup();
}

