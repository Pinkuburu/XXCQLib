// rake.c

#include <weapon.h>
#include <ansi.h>

inherit FORK;

void create()
{
        set_name(HIW"钢耙"NOR, ({ "gang pa", "pa","rake" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 1000);
                set("material", "iron");
		set("distance", 3);
                set("long", "一柄长长的七齿钢耙，是晾晒粮食时候用的。\n");
                set("wield_msg", "$N抄起一柄$n，在头上挥舞了一圈。\n");
        }
        init_fork(20);
        setup();
}