// jinjiasha.c 金澜袈裟
// by Load

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIY"金澜袈裟"NOR, ({ "jia sha", "sha", "cloth" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", "一件金光灿灿的金澜袈裟，只有少林高僧才可穿着。\n");
		set("value", 0);
                set("material", "cloth");
                set("armor_prop/armor", 30);
        }
        setup();
}

