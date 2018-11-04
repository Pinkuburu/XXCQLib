// bandage.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(YEL"虎骨贴"NOR, ({ "hugu tie", "hugu", "tie" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "贴");
		set("long", "这是一贴少林自制烘制的虎骨贴，因为含有虎骨粉，所以贴(tie)在患处活血效果很好。\n");
		set("value", 1000);
	}
}

void init()
{
	add_action("do_tie", "tie");
}

int wear() { return 0; }

int do_tie(string arg)
{
	if (!id(arg))
		return notify_fail("你要吃什么？\n");

	if ((int)this_player()->query("eff_qi") == 
	    (int)this_player()->query("max_qi"))
		return notify_fail("你现在不需要贴虎骨贴。\n");

	else {
		message_vision("$N拿出一贴虎骨贴，揉了揉身上的瘀青，“啪”的一声就将膏药贴在了身上。\n", this_player());
		this_player()->apply_condition("hugutie", 20);
		destruct(this_object());
	}
}
