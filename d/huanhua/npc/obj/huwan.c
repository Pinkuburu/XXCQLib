// huwan.c

#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create()
{
	set_name( "牛皮护腕", ({ "hu wan", "huwan" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "副");
                set("long", "这是一副皮质的护腕，上面满布铁钉，用以保护腕部。\n");
		set("value", 600);
		set("material", "wrists");
		set("armor_prop/armor", 5);
	}
	setup();
}
