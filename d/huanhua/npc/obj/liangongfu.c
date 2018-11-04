// liangong-fu.c

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("练功服", ({ "liangong fu", "cloth" }));
	set("long", "这是一件有点旧的练功服，由上好的麻布制成，有相当的防护力。\n");
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "件");
		set("value", 200);
		set("armor_prop/armor", 10);
	}
	setup();
}
