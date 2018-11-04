// jinjia.c 金甲

#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name(HIY"金环锁子甲"NOR, ({"jin jia","jinjia", "jia", "armor"}));
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else
	{
                set("unit", "件");
		set("long", "一件金线金麟织就的铠甲，只有将军才能穿．\n");
                set("material", "steel");
                set("value", 50000);
		set("wear_msg","“哗啦啦”一阵乱响，$N已将"HIY"金环锁子甲"NOR"穿在身上，真的威风八面！\n");
                set("armor_prop/armor", 40);
		set("armor_prop/dodge", -10);
        }
        setup();
}


