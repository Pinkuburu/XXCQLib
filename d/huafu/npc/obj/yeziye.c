// yeziye.c 椰子叶
// mlf设计,lks编程

#include <ansi.h>

inherit ITEM;
inherit F_AUTOLOAD;

void create()
{
	set_name(HIW"椰子叶"NOR,({"yeziye"}));
	set_weight(500);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("long","这是一支铁做的椰子形状的东西，两边呈齿状。\n");
                set("value", 0);
                set("material", "iron");
                set("no_drop","这东西不能离开你。\n");
              }
}
	

int query_autoload()
{
       object ob;
	ob=this_player();
	if(objectp(ob)&&userp(ob)){
		if (wizardp(this_player()))
       return 1;
	}
       return 0;
}

