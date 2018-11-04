// tiezhitao.c 铁指套
// by Load 

#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
	set_name( WHT"铁指套"NOR, ({ "zhi tao", "tao", "zhi" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "副");
                set("long", "这是五个环环相链的铁指套，可以保护指关节。\n");
		set("value", 800);
		set("material", "finger");
		set("armor_prop/armor", 5);
	}
	setup();
}
