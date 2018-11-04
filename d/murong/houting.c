// houting.c

#include <ansi.h>
inherit ROOM;
void create()
{
         set("short",HIW"后厅"NOR);
         set("long", @LONG
这里是慕容家里商议事情的地方，不是慕容弟子最好不要到这里来。在
后堂正中摆放着一个香案，上面摆放着一个灵位牌子(paizi)。
LONG
    );
         set("item_desc",([
             "paizi" : HIY"\t\t\t慕\n"
             	       	  "\t\t\t容\n"
             	       	  "\t\t\t世\n"
             	       	  "\t\t\t代\n"
             	       	  "\t\t\t祖\n"
             	       	  "\t\t\t先\n"
			  "\t\t\t灵\n"
			  "\t\t\t位\n"NOR

]));
         set("exits",([
             "east" : __DIR__"sf",
             "west" : __DIR__"xf1",                    
             "south" : __DIR__"cl2",
             "north" : __DIR__"yanziwu",
]));
	 set("objects",([
	 __DIR__"npc/feng" : 1,
]));
         setup();       
}

void init()
{
	add_action("ketou", "ketou");
}

int ketou(string arg)
{
	object me;
	me = this_player();
	
        if( !living(me))                             
        	return 0;                            
        if( me->is_busy())
        	return 0;
        if( me->is_fighting())
        	return 0;
        if( !me->query("jifen"))
        	return 0;
        if(arg)
        	return notify_fail("你要干什么？\n");     
        if(!arg)
        {
        	message_vision("$N恭恭敬敬地跪倒在地，对着灵位磕头。\n", me);
        	me->set("ketou", 1);
        	return 1;
        }
}

