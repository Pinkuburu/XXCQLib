// peizi.c

inherit ITEM;

void create()
{
	set_name("醅子", ({"peizi"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一种制酒的原料。\n");
		set("unit", "个"); 
		set("value", 40);
	}
}