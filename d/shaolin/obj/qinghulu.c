// qinghulu.c 清水葫芦
// by Load

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(CYN"清水葫芦"NOR, ({"hulu", "bottle"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用青葫芦制成的水壶，可以随身携带。\n");
		set("unit", "个");
		set("value", 100);
		set("max_liquid", 10);
	}

	set("liquid", ([
		"type": "water",
		"name": "山泉水",
		"remaining": 10,
		"drunk_supply": 30,
	]));
}