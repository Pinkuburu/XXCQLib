// yitian-jian 倚天剑

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(YEL"金虹剑"NOR,({ "jinhong jian","sword" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 100000);
                set("material", "steel");
                set("long", "这是一柄四尺来长的金红色宝剑，是天羽派掌门信物，见剑如剑掌门。\n");
                set("wield_msg", HIY "只听“唰”的一声，天空中闪过一道金虹，$n在空中飞旋落入$N手中。\n" NOR);
                set("unwield_msg", HIY "金虹剑「唰」地飞入了剑鞘。\n" NOR);
                }
        init_sword(110);
        setup();
}
