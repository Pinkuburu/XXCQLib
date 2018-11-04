// tiehuwan.c 铁护腕
// by Load

#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create()
{
	set_name( WHT"铁护腕"NOR, ({ "hu wan", "huwan", "wan" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "双");
                set("long", "这是一件皮质的护腕，上面满布铁钉，用以保护腕部。\n");
		set("value", 300);
		set("material", "wrists");
		set("armor_prop/armor", 4);
	}
	setup();
}
