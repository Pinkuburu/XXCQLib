// dhjiudai.c  雕花酒袋 by load

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(CYN"雕花酒袋"NOR, ({"jiudai", "dai"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个看上去相当高贵的雕花酒袋，一般是富人才用的。\n");
		set("unit", "个");
		set("value", 120);
		set("max_liquid", 20);
         set("container",1);
	}

	set("liquid", ([
		"type": "alcohol",
		"name": "竹叶青",
		"remaining": 20,
		"drunk_apply": 20,
	]));
}

