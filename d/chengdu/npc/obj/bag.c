#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(WHT"布袋"NOR, ({ "bu dai", "bag", "dai" }) );
        set_weight(500);
        set_max_encumbrance(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "口");
                set("long", "这是一口寻常的布袋，可以用来装一些杂物。\n");
                set("value", 100);
        }
}

int is_container() { return 1; }

