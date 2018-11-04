// gangdao.c

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("柴刀", ({ "chaidao" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("unit", "把");
                set("long", "这是一把砍柴用的柴刀。\n");
                set("value", 3);
                set("material", "iron");
                set("wield_msg", "$N拿出一把$n，拿在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
	}
	init_blade(5);
	setup();
}
