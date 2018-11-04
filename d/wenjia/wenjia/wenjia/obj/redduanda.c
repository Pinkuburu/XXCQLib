// Item redduanda.c 劲装短打
// Created by Zeus 1999.5.28
// Modified by Zeus 1999.5.28
// 
// 

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIR"劲装短打"NOR, ({ "duanda" }));
        set("long", "这是一件红色的" + HIR"劲装短打"NOR + "，这是温家第六代弟子的统一装束，有一定的防护力。\n");
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
                set("value", 200);
                set("armor_prop/armor", 10);
        }
        setup();
}
