// Item cailiaokey.c
// Created by Zeus 1999.5.12
// Modified by Zeus 1999.5.12
// 
// 

inherit ITEM;

void create()
{
        set_name("材料房的钥匙", ({"cailiaokey"}));
             if( clonep() ) set_default_object(__FILE__);
        else {
        set("long",
               "这是一片钥匙。\n");
        set("unit", "片");
        set("weight", 10);
        }
}
