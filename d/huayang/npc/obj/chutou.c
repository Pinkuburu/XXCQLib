// bigaxe.c

#include <weapon.h>
#include <ansi.h>

inherit AXE;

void create()
{
	set_name(YEL"锄头"NOR, ({ "chu tou", "chu", "tou" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把木柄钢头的锄头，看上去很结实。\n");
		set("value", 1000);
		set("distance", 3);
		set("wield_msg", "$N拿出一把$n，一个没拿稳，差点砸在自己脚上。\n");
		set("unwield_msg", "$N放下手中的$n，气喘吁吁地擦了擦汗。\n");
	}
	init_axe(20);
	setup();
}
