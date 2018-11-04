// jiedao.c 戒刀
// by Load

#include <ansi.h>
#include <weapon.h>

inherit CLUB;

void create()
{
	set_name(YEL"木臂"NOR, ({ "mubi" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("value", 500);
		set("material", "wood");
		set("distance", 2);
		set("long", "这是一柄尺半长的戒刀，刀光闪闪，入手沉重，似是精铁打成。\n");
		set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
	}
	init_club(20);
	setup();
}
