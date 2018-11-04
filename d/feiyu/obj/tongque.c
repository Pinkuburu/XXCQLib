// gangdao.c



#include <weapon.h>

#include <ansi.h>

inherit F_UNIQUE;

inherit SWORD;



void create()

{

        set_name(HIC"铜雀"NOR, ({ "tongque","jian","sword" }));

        set_weight(5000);

        if (clonep())

                set_default_object(__FILE__);

        else {

                set("unit", "柄");

                set("long", @LONG

这就是名震江湖,剑中龙凤之一的铜雀剑,此剑细小,通体白色,入手极

寒,可碎金断玉,与太阿剑配为一对,原为"龙凤双剑侠"所有,后被藏剑

老人谷风晚所夺.

LONG);

                set("value", 50000);

                set("no_break", 1);

                set("endure", 150);

                set("material", "steel");

                set("wield_msg", HIY"$N轻轻的自鞘中拔出宝剑"HIC"铜雀"NOR+HIY"，只见精光湛潋,犹如透明的水棒一般,"NOR+HIC"水光滟然,寒气逼人。\n"NOR);

                set("unwield_msg", HIY"$N轻轻的将手中的"NOR+HIC"铜雀"NOR+HIY"插入剑鞘，水光乍然消失,而那寒气却仍未消散。\n");

        }

        init_sword(50);

        setup();

}


