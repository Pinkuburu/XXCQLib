// laozi16.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( WHT"三国志"NOR, ({ "sanguozhi", "book", "sanguo","shu" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","　　滚滚长江东逝水，浪花淘尽英雄。是非成败转头空。

　　青山依旧在，几度夕阳红。　　白发渔樵江渚上，惯

　　看秋月春风。一壶浊酒喜相逢。古今多少事，都付

　　笑谈中。

　　——调寄《临江仙》\n");
		set("value", 2000);
		set("material", "paper");
		set("skill", ([
			"name":	"literate",
			"exp_required":	0,
			"jingli_cost":  15,
			"difficulty":	10,
			"max_skill":	55,
			"min_skill":	30,
		]) );
	}
}