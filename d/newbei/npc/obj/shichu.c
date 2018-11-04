// gangzhang.c 钢杖

#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("石杵", ({ "shichu" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一根粗重的石杵，药店一般都用来舂药。\n");
                set("value", 3);
                set("material", "iron");
                set("wield_msg", "$N拿出一把$n，拿在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
	}
        init_hammer(5);
	setup();
}
