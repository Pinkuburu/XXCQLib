// Item yaochu.c  
// Modified by Atlus 10.14.1999
// 

inherit ITEM;

void create()
{
        set_name( "未处理过的圆铁块",({ "tie kuai"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long","这是一个未处理过的圆铁块。\n");
                set("value", 50);
                set("material", "iron");
        }
}
