// chanzhang.c 禅杖
// by Load

#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
        set_name(CYN"禅杖"NOR, ({ "chan zhang", "zhang", "staff" }));
        set_weight(20000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根黑黝黝的镔铁禅杖，约四十来斤，是件称手的重兵器。\n");
                set("value", 800);
		set("rigidity", 150);
                set("material", "iron");
                set("wield_msg", "$N双臂一振，已经拾起一根$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n顺在身后。\n");
        }
        init_staff(25);
        setup();
}