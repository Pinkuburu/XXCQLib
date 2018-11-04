//Obj 柴刀
//BY godzilla 11.18.99

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
	set_name(RED"柴刀"NOR, ({ "chaidao", "dao" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一把劈柴用的柴刀。\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回腰间。\n");
	}
	init_blade(5);
	setup();
}
