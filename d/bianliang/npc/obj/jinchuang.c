// jinchuang.c 金创药

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_fu", "fu");
}

void create()
{
	set_name(HIY"金创药"NOR, ({"jinchuang yao", "yao", "jin", "jinchuang"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "包");
		set("long", "这是一包用来止血的上好的金创药，是用来敷(fu)在伤口上的。\n");
		set("value", 2000);
	}
	setup();
}

int do_fu(string arg)
{
	if (!id(arg))
		return notify_fail("你要敷什么药？\n");
	if ((int)this_player()->query("eff_qi") == 
	    (int)this_player()->query("max_qi"))
		return notify_fail("你现在不需要用金创药。\n");
	else {
		this_player()->receive_curing("qi", 30);
		message_vision("$N小心翼翼的将金创药敷在伤口上，伤口马上看来好了不少。\n", this_player());
		destruct(this_object());
		return 1;
	}
}