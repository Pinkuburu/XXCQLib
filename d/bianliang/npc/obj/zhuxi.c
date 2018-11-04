// laozi16.c

#include <ansi.h>

inherit ITEM;

void create()
{
    set_name( WHT"朱熹文集"NOR, ({ "zhuxi wenji", "wenji", "book" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","Sorry,我也没读过。

    决战\n");
        set("value", 20000);
		set("material", "paper");
		set("skill", ([
			"name":	"literate",
			"exp_required":	0,
            "jingli_cost":  80,
			"difficulty":	10,
            "max_skill":    180,
            "min_skill":    120,
		]) );
	}
}
