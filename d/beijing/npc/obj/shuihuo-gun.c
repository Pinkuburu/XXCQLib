// shuihuogun.c 水火棍
//摘自《温柔一刀》，官差常用兵器

#include <weapon.h>
inherit CLUB;

#include <ansi.h>

void create()
{
	set_name(HIR"水火棍"NOR, ({ "shuihuo gun", "gun", "club" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一根通红的长棍，巡捕常用他来抓人。\n");
		set("value", 100);
		set("material", "steel");
		set("wield_msg", "$N提起一根$n握在两手中。\n");
		set("unwield_msg", "$N将手中的$n顺到背后。\n");
	}
	init_club(25);
	setup();
}
