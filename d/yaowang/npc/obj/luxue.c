// ¹Ѫ ҩ��ׯ��ҩ�ĵ��ߡ�
// By ɽèAdx 16:53 99-10-25

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name( HIR "¹Ѫ" NOR , ({"lu xue", "xue"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��÷��¹Ѫ��\n");
		set("unit", "��");
		set("yaowang", 1);
		set("value", 1000);
		set("weight", 1000);
	}
}
