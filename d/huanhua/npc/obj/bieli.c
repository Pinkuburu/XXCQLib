// gangdao.c

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit SWORD;

void create()
{
	set_name(HIW"别离良剑"NOR, ({ "bieli liangjian","liangjian","jian","sword" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄剑锋两侧带有些许锯齿的异型剑，是著名剑客孟别离的佩剑。\n");
		set("value", 1000);
		set("rendu", 200);
		set("material", "steel");
		set("wield_msg", WHT"$N反手一拔，$n"WHT"出鞘，如一道电光裂空。\n"NOR);
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
	}
	init_sword(45);
	setup();
}