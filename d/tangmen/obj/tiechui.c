//tiechui.c


inherit ITEM;

void create()
{
        set_name("铁锤", ({"tie chui", "chui"}));
	set_weight(20000);
        set("unit", "柄");
        set("long", "这是一柄分量不轻的大铁锤，可以用来砸碎石块。\n");
        set("value", 1000);
        setup();
}