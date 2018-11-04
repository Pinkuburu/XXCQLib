// gangzhang.c 钢杖

#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("扇子", ({ "shanzi" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一根竹制的扇子。\n");
                set("value", 3);
                set("material", "iron");
                set("wield_msg", "$N拿出一把$n，握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
	}
        init_hammer(5);
	setup();
}
