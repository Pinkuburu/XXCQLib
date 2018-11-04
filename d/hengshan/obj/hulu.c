// hulu.c 

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("大葫芦", ({"da hulu", "hulu", }));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一个用葫芦制成的水壶。\n");
                set("unit", "个");
                set("value", 100);
                set("max_liquid", 55);
        }
       
        set("liquid", ([
                "type": "water",
                "name": "泉水",
                "remaining": 55,
                "drunk_supply": 55,
        ]));
}

