// gangdao.c

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit SWORD;
int do_chou(string arg);
int do_shou(string arg);

void create()
{
	set_name(YEL"笤帚"NOR, ({ "tiaozhou" }));
	set_weight(9000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", @LONG
一把普普通通的笤帚。
LONG);
		set("value", 100);
		set("nopawn",1);
		set("material", "wood");
		set("wield_msg", CYN"$N举起手中的笤帚当作武器。\n"NOR);
	}
	init_sword(5);
	setup();
}

void init()
{
	add_action("do_chou","chou");
	add_action("do_shou","shou");
}

int do_chou(string arg)
{
	object me, ob;

	me = this_player();
	ob = this_object();

	if (!arg || (arg!="jian" && arg!="sword") || ob->query("val"))
		return notify_fail("你要抽什么？\n");

	message_vision(YEL"$N缓缓的自笤帚里抽出一把断剑，一柄无光色、陈旧、有裂纹、如古松一般的断剑。\n"NOR, me);
	ob->set_name(YEL"古松残阙"NOR, ({ "gusong canque","canque", "jian","sword" }));
	set("long", @LONG
这是一柄无光色、陈旧、有裂纹、如古松一般的断剑。
LONG);
	ob->set("value", 50000);
	ob->set("nopawn",1);
	ob->set("no_break", 1);
	ob->set("endure", 150);
	ob->set("val",1);
	ob->set("material", "steel");
	ob->set("wield_msg", HIY"$N举起手中的"NOR + YEL"古松残阙"HIY"，剑身轻颤，发出阵阵龙吟。\n"NOR);
	ob->set("weapon_prop/damage",70);
	return 1;
}

int do_shou(string arg)
{
	object me, ob;

	me = this_player();
	ob = this_object();

	if (!arg || (arg!="jian" && arg!="sword") || !ob->query("val"))
		return notify_fail("你要收什么？\n");

	message_vision(YEL"$N将古松残阙重新收回了那把普普通通的笤帚中。\n"NOR, me);
	ob->set_name(YEL"古松残阙"NOR, ({ "gusong canque","canque", "jian","sword" }));
	ob->set_name(YEL"笤帚"NOR, ({ "tiaozhou" }));
	ob->set("long", @LONG
一把普普通通的笤帚。
LONG);
	ob->set("value", 100);
	ob->set("material", "wood");
	ob->set("val",0);
	ob->set("wield_msg", CYN"$N举起手中的笤帚当作武器。\n"NOR);
	ob->set("nopawn",1);
	ob->set("weapon_prop/damage",5);
	return 1;
}
