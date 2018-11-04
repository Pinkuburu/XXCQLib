// tiebeixin.c 铁背心
// by Load

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(WHT"铁背心"NOR, ({ "tie beixin", "beixin" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "一件生铁打造的护心背心，保护前心后背不受致命伤害。\n");
		set("value", 500);
		set("material", "cloth");
		set("armor_prop/armor", 15);
	}
	setup();
}
