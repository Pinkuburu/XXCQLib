// bajiaoye.c 芭蕉叶
// mlf设计,lks编程

#include <ansi.h>

inherit ITEM;
inherit F_AUTOLOAD;

void create()
{
	set_name(HIW"芭蕉叶"NOR,({"bajiaoye"}));
	set_weight(500);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("long","这是一支铁做的芭蕉形状的东西，状如关刀。\n");
                set("value", 0);
                set("material", "iron");
                set("no_drop","这东西不能离开你。\n");
              }
}
int query_autoload()
{
       if (wizardp(this_player()))
       return 1;
       else return 0;
}
