// plow.c

#include <weapon.h>
#include <ansi.h>

inherit HAMMER;

void create()
{
        set_name(CYN"犁头"NOR, ({"li tou", "plow", "li"}));
        set_weight(50000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把黑黝黝的犁头，看上去确实只有老牛才拉得动。\n");
                set("value", 5000);
                set("material", "iron");
		set("distance", 1);
                set("wield_msg", "$N横握起$n，发现实在太不适手，干脆抱在怀里。\n");
                set("unwield_msg", "$N放下手中的$n，累得浑身都是臭汗，就快虚脱了。\n");
        }

        init_hammer(25);
        setup();
}

