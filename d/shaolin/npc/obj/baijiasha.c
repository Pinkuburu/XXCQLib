// baijiasha.c 白布黑边袈裟
// by Load

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(HIW"白布"HIB"黑边"HIW"袈裟"NOR, ({ "jia sha", "sha", "cloth" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", "这是一件看上去普普通通的白布袈裟，其实坚韧无比，只有少林长老才可穿着。\n");
                set("material", "cloth");
		set("value", 10000);
                set("armor_prop/armor", 50);
        }
        setup();
}

