// fojing11.c

#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;

string* titles = ({
	"具舍论经",
	"佛本行经",
	"五龙经",
	"摩羯经",
	"三论别经",
});

void create()
{
	set_name(YEL + titles[random(sizeof(titles))] + NOR, ({ "jing", "shu", "book" }));
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long", "这是一册佛经，书页已经泛黄，里面记载了许多深奥的禅宗思想。\n");
		set("value", 1000);
		set("material", "paper");
		set("replace_file", "/d/shaolin/obj/jing1");
		set("skill", ([
			"name":	"buddha",
			"exp_required" : 0,
			"jingli_cost" :	50,
			"difficulty" : 20,
			"min_skill" : 41,
			"max_skill" : 80,
		]));
	}
}