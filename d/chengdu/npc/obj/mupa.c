
#include <weapon.h>

inherit RAKE;

void create()
{
        set_name("木耙", ({"mu pa", "pa", "rake"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 400);
                set("material", "wood");
		set("distance", 3);
                set("long", "这是一柄长长的木耙，是晾晒粮食时候用的。\n");
                set("wield_msg", "$N抽出一柄$n握在手中。\n");
        }
        init_rake(10);
        setup();
}

