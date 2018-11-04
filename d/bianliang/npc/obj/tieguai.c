// gangzhang.c 钢杖

#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
	set_name(WHT"铁拐"NOR, ({ "tiezhang", "zhang" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一根黝黑粗重的铁拐。\n");
		set("value", 1500);
		set("rigidity",100);
		set("material", "iron");
		set("distance", 3);
		set("wield_msg", "$N抽出一根$n颠了颠，握在双手中。\n");
		set("unwield_msg", "$N将手中的$n插回腰间。\n");
	}
  	init_staff(25);
	setup();
}