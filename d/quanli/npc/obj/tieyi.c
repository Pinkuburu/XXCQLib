// jinjia.c 金甲

#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name(HIY"铁衣"NOR, ({"tie yi","tie", "yi", "armor"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else
	{
                set("unit", "件");
		set("long", "一件由方寸大薄铁片织就的黑色铁衣。\n");
                set("material", "steel");
                set("value", 50000);
                set("armor_prop/armor", 20);
		set("armor_prop/dodge", -5);
        }
        setup();
}