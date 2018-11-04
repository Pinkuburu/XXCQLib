// suijiasha.c 灰布镶边袈裟
// by Load

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(WHT"灰布镶边袈裟"NOR, ({ "jia sha", "cloth", "sha" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", "一件灰色精布缝制的长袖袈裟，少林寺一般僧人都穿这种袈裟。\n");
                set("material", "cloth");
		set("value", 0);
                set("armor_prop/armor", 4);
        }
        setup();
}