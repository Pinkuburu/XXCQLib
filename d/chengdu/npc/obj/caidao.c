// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("菜刀", ({ "cai dao", "dao"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 200);
		set("material", "iron");
		set("distance", 1);
		set("long", "这是一把切菜用的菜刀，着急了用它跟人拼命也成。\n");
		set("wield_msg", "$N抽出一把血淋淋的$n握在手中。\n");
		set("unequip_msg", "$N将$n小心的别在腰上。\n");
	}
	init_blade(8);
	setup();
}
