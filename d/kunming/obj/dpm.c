inherit SR_DANGPU;

void create()
{
    set_name("当铺柜台", ({ "table" }) );
    set("long", "这是一个又破又旧了的柜台，可是要办好一个当铺还真离不开它呢！\n" );
    setup();
    replace_program(SR_DANGPU);
}