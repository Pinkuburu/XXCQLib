// shoes.c
#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
        set_name(GRN"踏雪无痕"NOR, ({ "shoes", "xie" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long","这是一双小巧的女儿鞋。\n");        
                set("unit", "双");
                set("material", "boots");
                set("armor_prop/dodge", 1);
        }
        setup();
}
