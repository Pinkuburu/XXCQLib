// changjian.c 长剑
// by Load

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(WHT"长剑"NOR, ({ "chang jian", "jian", "sword" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄五尺长的普通生铁剑，一般的剑客都配带此剑。\n");
		set("value", 500);
		set("distance", 2);
		set("material", "iron");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
	}
	init_sword(15);
	setup();
}
