//key.c
inherit ITEM;
void create()
{
       set_name( "拜帖", ({ "bai tie","tie" }));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long","这是一张武林的拜帖。\n");
                set("value", 0);
                set("material", "paper");
                set("no_drop","这东西不能离开你。\n");
              }
}
