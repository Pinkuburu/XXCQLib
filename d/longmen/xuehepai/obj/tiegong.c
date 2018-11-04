
#include <weapon.h>
#include <ansi.h>
inherit ARROW;

void create()
{
        set_name(CYN"铁弓"NOR, ({ "tie gong", "gong" ,"arrow"}));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把普通的铁弓，一般的射手都配带此弓。\n");
                set("value", 1000);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声从背后拿出一把$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回背后。\n");
        }
        init_arrow(25);
        setup();
}

