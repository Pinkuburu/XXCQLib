// bandage.c

#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("抹布", ({ "mabu" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("unit", "块");
                set("long", "这是一块布头，不知是从哪撕下来的。\n");
                set("value", 3);
                set("material", "iron");
                set("wield_msg", "$N拿出一块$n，拿在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
	}
  	init_staff(5);
        setup();
}