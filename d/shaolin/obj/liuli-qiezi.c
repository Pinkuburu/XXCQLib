// liuli-qiezi.c ��������

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIB"��������"NOR, ({"liuli qiezi", "qiezi"}));
	set_weight(500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�������䣬���͸�ã�����������������ӡ�\n");
		set("unit", "��");
		set("value", 1);
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
