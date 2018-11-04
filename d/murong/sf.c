// shufang.c
#include <ansi.h>                   
#include <localtime.h>
inherit ROOM;

void create()
{
         set("short",HIW"书房"NOR);
         set ("long",@long
这里是燕子坞的书房, 天下武功皆荟粹与此, 包罗万象, 屋子南边是一
把坐椅,四周全是一排排高大的书架。好好学习, 必可成为一代高手。
long);
         set("exits",([
             "west" : __DIR__"houting",
]));
	setup();
}


void init()
{
        add_action("sit", "sit");
        add_action("zhuan", "zhuan");
        add_action("press", "press");
}


int sit(string arg)
{
	object me;
	me=this_player();
	
	if (!arg) return 0;
	if (me->is_busy()) return 0;
	if (me->is_fighting()) return 0; 
	if (arg !="chair") return 0;
	if (me->query_temp("marks/坐1"))
			return notify_fail("你已经坐在上面了。\n");
	if (arg=="chair")
	{
		write("你坐在椅子上，真是悠闲自得。\n");
		tell_object(me, "你发现椅子上有一个小机关。\n");
		me->set_temp("marks/坐1", 1);
		return 1;
	}
}
int zhuan(string arg)
{
	object me;
	me=this_player();                
	if (!arg) return 0;
	if (me->is_busy()) return 0;
	if (me->is_fighting()) return 0; 
	if (!me->query_temp("marks/坐1")) return 0;	
	switch(arg)
	{                                                           
		case "左" :
		case "left" :
		write("你把机关向左推了一下，机关又回到了原位。\n");
		me->add_temp("push/left", 1);
		break;
		case "右" :
		case "right" :
		write("你把机关向右推了一下，机关又回到了原位。\n");
		me->add_temp("push/right", 1);			
		break;
		case "上" :
		case "up" :
		write("你把机关向上推了一下，机关又回到了原位。\n");
		me->add_temp("push/up", 1);			
		break;
		case "下" : 
		case "down" :
		write("你把机关向下推了一下，机关又回到了原位。\n");
		me->add_temp("push/down", 1);
		break;
		
		default : return notify_fail("什么？\n");
	}                                                
	return 1;
}
int press()
{
	mixed *ltime;
	int hour, min, i, j, k, l;	
	object me;
	me=this_player();                
	ltime = localtime(time());
	hour = ltime[LT_HOUR];	
	min = ltime[LT_MIN];     
	i = (int)me->query_temp("push/up");
	j = (int)me->query_temp("push/down");
	k = (int)me->query_temp("push/left");
	l = (int)me->query_temp("push/right");
	if( wizardp(me))
	{
		write(hour+"\n");
		write(i+"\n");   
		write(min+"\n");
		write(j+"\n");	
		write((min+hour)+"\n");
		write(k+"\n");	       
		write((min-hour)+"\n");
		write(l+"\n");		
	}
	if( !wizardp(me))
	{
            	me->delete_temp("marks/坐1");
            	me->delete_temp("push/up");
            	me->delete_temp("push/down");
            	me->delete_temp("push/right");
            	me->delete_temp("push/left");
	}	
	if( (i > hour) 
	 && (j > min)
	 && (k > (hour+min))
	 && (l > (min-hour))
	 && (min-hour) >0)
         {            
		tell_object(me, "你试着按下了机关，突然椅子向后一转。\n");
    	        me->move(__DIR__"hssg");
		message("vision", me->name() + "坐着椅子转了过来。\n", environment(me), ({me}) );
            	me->delete_temp("marks/坐1");
            	me->delete_temp("push/up");
            	me->delete_temp("push/down");
            	me->delete_temp("push/right");
            	me->delete_temp("push/left");		
            	return 1;
	}      
	write("你试着按下机关，可是一点反应也没有。\n");
	return 1;
}

