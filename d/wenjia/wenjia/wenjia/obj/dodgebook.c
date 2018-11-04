// Item dodgebook.c
// Created by Zeus 1999.3.28
// Modified by Zeus 1999.7.22
// 
// 

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name( YEL"基本轻功（提高篇）"NOR,({ "dodge book"}));
        set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","这是一本"YEL"基本轻功（提高篇）。\n"NOR);
                set("value", 500);
                set("material", "paper");
                set("skill", ([
                        "name": "dodge",           //name of the skill
                        "exp_required": 0 ,        //minimum combat experience required
                        "jingli_cost":  35,        // jingli cost every time study this
                        "difficulty":   10,        // the base int to learn this skill
                        "max_skill":    61         // the maximum level you can learn
                ]) );
        }
}
