// junfu.c

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("黄衣军服", ({ "junfu", "fu", "cloth" }));
	set("long", "这是一件有点旧的黄衣军服，背后大大的绣有汴梁两个字。\n");
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "件");
		set("value", 200);
		set("armor_prop/armor", 5);
	}
	setup();
}
