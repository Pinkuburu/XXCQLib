// Item swordbook.c
// Created by Zeus 1999.3.28
// Modified by Zeus 1999.3.28
// 
// 

inherit ITEM;

void create()
{
        set_name( "基本剑法（入门篇）",({ "shu","book"}));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","这是一本基本剑法（入门篇）。\n");
                set("value", 500);
                set("material", "paper");
                set("skill", ([
                        "name": "sword",            //name of the skill
                        "exp_required": 0 ,        //minimum combat experience required
                        "jingli_cost": 20+random(20),// jing cost every time study this
                        "difficulty":   20,        // the base int to learn this skill
                        "max_skill":    31         // the maximum level you can learn
                ]) );
        }
}
