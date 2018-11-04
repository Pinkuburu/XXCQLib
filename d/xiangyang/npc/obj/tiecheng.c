// gangzhang.c 钢杖

#include <weapon.h>
#include <ansi.h>
inherit STICK;

void create()
{
	set_name(WHT"铁秤"NOR, ({ "tie cheng", "tie", "cheng" }));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "杆");
		set("long", "这是一个铁打的秤，不过看上去更像一件武器。\n");
		set("value", 1500);
		set("rigidity",100);
		set("material", "iron");
		set("wield_msg", "$N从腰间一杆$n握在手中当武器。\n");
		set("unwield_msg", "$N将手中的$n插回腰间。\n");
	}
  	init_stick(15);
	setup();
}
