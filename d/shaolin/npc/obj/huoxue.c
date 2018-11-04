// jinchuang.c 金创药

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
	add_action("do_eat", "fu");
	add_action("do_eat", "chi");
}

void create()
{
	set_name(HIM"活血丹"NOR, ({"huoxue dan", "dan", "huoxue"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗少林自制的活血丹，舒经活络、清血化瘀有很好的效果。\n");
		set("value", 1000);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
		return notify_fail("你要吃什么？\n");

	if ((int)this_player()->query("eff_qi") == 
	    (int)this_player()->query("max_qi"))
		return notify_fail("你现在不需要服用活血丹。\n");

	else {
		this_player()->receive_curing("qi", 30+random(30));
		message_vision("$N拿出一颗活血丹，一仰脖便吞了下去，脸色立时看起来好了一些。\n", this_player());
		destruct(this_object());
		return 1;
	}
}