// liutiao.c 柳条

#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(GRN"断成三截的柳树条"NOR,({ "liu tiao", "liutiao" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "枝");
                set("value", 0);
                set("material", "bamboo");
                set("long", "这是一枝柳树条。\n");
        }
        setup();
}
