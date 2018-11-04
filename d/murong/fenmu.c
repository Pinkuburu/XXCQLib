// fenmu.c
#include <ansi.h>
#include <localtime.h>
inherit ROOM;

void create()
{
        set("short",HIB"坟墓"NOR);
        set("long", 
"这里是慕容氏的祖坟, 慕容氏死后都要被安葬这里，世世代代, 无一例\n"
"外。每到清明时分, 慕容后裔都要在这里祭祖。\n"
);
        set("exits", ([
                "west" : __DIR__"cl3",
        ]));
	set("objects",([
	__DIR__"npc/deng" : 1,
]));
        set("outdoors", "姑苏慕容");
        setup();                          
}

void init()
{
	object me = this_player();      
/*	if( me->query("family/family_name") == "姑苏慕容"
	&&  me->query("family/generation") == 2 )
	{
		message_vision("突然一个蒙面人掠起$N飞向房顶。\n", me); 
		me->move(__DIR__"roof");
	}
*/	add_action("do_ketou", "ji");
}

int do_ketou(string arg)
{                                            
	mixed *ltime;
	int current_month, current_day, current_hour;
	object me;
	me = this_player();             
	ltime = localtime(time());
	current_month = ltime[LT_MON]+1;
	current_day = ltime[LT_MDAY];                     
	current_hour = ltime[LT_HOUR];
	if( !living(me) )
		return 0;
	if( !arg || arg =="" || arg != "fen")
		return 0;
	if( me->query("family/family_name") != "姑苏慕容")
		return 0;
	if( me->query("family/generation") != 3)                             
		return 0;
	if( arg == "fen")
	{                                                                    
		
		if(current_month == 4 && current_day == 5 && current_hour == 1)
		me->set("jifen", 1);
		message_vision("$N恭恭敬敬的跪倒在地，冲着坟墓磕头。\n", me);
		return 1;
	}
		
}		