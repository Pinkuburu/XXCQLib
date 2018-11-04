// changqiang.c

#include <weapon.h>

inherit SPEAR;

void create()
{
	set_name("点钢枪", ({ "diangang qiang","qiang" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "杆");
		set("value", 1000);
		set("material", "steel");
		set("distance", 4);
		set("long", "一杆精钢打制的威风粼粼的点钢枪。\n");
		set("wield_msg", "$N抄起一杆$n，顺手抖了个枪花。\n");
		set("unwield_msg", "$N哼了一声，将$n插回后腰。\n");
	}
	init_spear(30);
	setup();
}
