// mudao.c

#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name(YEL"木鱼槌"NOR, ({ "muyu chui", "chui" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 50);
		set("material", "wood");
		set("long", "这是一把和尚念经敲木鱼用的小木槌。\n");
		set("wield_msg", "$N从衣袋里掏出一根$n，握在手中当武器。\n");
		set("unequip_msg", "$N将手中的$n放回衣袋。\n");
	}
	init_hammer(2);
	setup();
}
