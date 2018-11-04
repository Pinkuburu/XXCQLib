// jinjia.c 金甲

#include <ansi.h>
#include <armor.h>

inherit SURCOAT;

void create()
{
        set_name(HIR"红锦披风"NOR, ({"hongjin pifeng","hongjin", "pifeng"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else
	{
                set("unit", "件");
		set("long", "一件上等红锦缝制的披风，绣有红日、红鸦，这是冷呼儿的独有披风\n");
                set("material", "cloth");
                set("value", 5000);
		set("wear_msg","“唰”一声响，$N一挥臂，将"HIR"红锦披风"NOR"披在身上，身形立时灵活了许多！\n");
                set("armor_prop/armor", 5);
		set("armor_prop/dodge", 10);
        }
        setup();
}


