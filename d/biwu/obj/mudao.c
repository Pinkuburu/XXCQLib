// gangdao.c

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("木刀", ({ "blade" }));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄精工制成的木刀，虽不致命，却可伤人。\n");
		set("value", 0);
		set("material", "bamboo");
		set("wield_msg", "$N拿出一把$n，握在手中。\n");
		set("unequip_msg", "$N放下手中的$n。\n");
	}
	init_blade(10);
	setup();
}
