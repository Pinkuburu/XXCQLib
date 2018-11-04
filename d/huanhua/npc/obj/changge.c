// gangdao.c

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit SWORD;

void create()
{
	set_name(HIC"长歌"NOR, ({ "changge","jian","sword" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", @LONG
这柄剑斑剥，陈旧、古意，只有剑锋口一处，隐冷地闪着。一种似波光似水
光但又如毒蛇蓝牙般的寒芒。
这是一柄萧家历代风云人物闯荡江湖的佩剑——古剑长歌！
LONG);
		set("value", 50000);
		set("no_break", 1);
		set("endure", 150);
      set("no_get","别人的东西就不要拣啦!\n");
      set("no_give","这个东西不能随便给人");
		set("material", "steel");
		set("wield_msg", CYN"$N剥开手中包裹，缓缓的自鞘中抽出"HIC"长歌"NOR+CYN"古剑，剑锋闪过一道"HIB"寒光。\n"NOR);
		set("unwield_msg", "$N将手中的$n插入剑鞘，又仔细的用包裹把剑包了起来。\n");
	}
    init_sword(100);
	setup();
}
