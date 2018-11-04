// kaoya.c 烤鸭

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(YEL"烧鸡"NOR, ({"shaoji", "ji"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一只刚刚出炉的道口烧鸡，让人看着就流口水。\n");
		set("unit", "只");
		set("value", 150);
		set("food_remaining", 4);
		set("food_supply", 60);
	}
}
