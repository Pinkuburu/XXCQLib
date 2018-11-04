// gangdao.c



#include <weapon.h>

#include <ansi.h>

inherit F_UNIQUE;

inherit SWORD;



void create()

{

        set_name(HIR"太阿"NOR, ({ "taier","jian","sword" }));

        set_weight(5000);

        if (clonep())

                set_default_object(__FILE__);

        else {

                set("unit", "柄");

                set("long", @LONG

这就是名震江湖,剑中龙凤之一的太阿剑,此剑剑身细小,通体火红,入

手极热,与铜雀剑配为一对,原为"龙凤双剑侠"所有,后被藏剑老人谷风

晚所夺.

LONG);

                set("value", 50000);

                set("no_break", 1);

                set("endure", 150);

                set("material", "steel");

                set("wield_msg", CYN"$N轻轻的自鞘中拔出宝剑"HIR"太阿"NOR+CYN"，只见精光湛潋,犹如一团燃烧的火炎,"NOR+HIR"熊熊燃烧,闪烁不已。\n"NOR);

                set("unwield_msg", CYN"$N轻轻的将手中的"HIR"太阿"NOR+CYN"插入剑鞘，火光乍然消失,而那热气却依旧逼人。\n");

        }

        init_sword(50);

        setup();

}


