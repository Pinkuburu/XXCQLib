// 锦缎
//By 山猫adx @ CuteRabbit 19:28 99-5-28

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIM"锦缎"NOR, ({ "jinduan", "jin", "duan" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", HIM"这是一件华丽的锦缎，城里的富豪们经常都穿。\n"NOR);
		set("wear_msg", WHT "$N拿出一件华丽的"+HIM"锦缎"NOR+WHT"穿在身上\n" NOR);
		set("remove_msg", WHT "$N将"+HIM"锦缎"NOR+WHT"从身上脱了下来。\n" NOR);
                set("material", "cloth");
		set("value", 5000);
                set("armor_prop/armor", 20);
        }
        setup();
}

