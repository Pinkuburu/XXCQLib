// Room: 柴房
// Date: by godzilla 1999.11.18

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "柴房");
	set("long", @LONG
这里是靠西边的柴房，房里杂七杂八的堆着各种各样的木柴，锯
木灰弥漫着整个空气，不时的传来嘈杂的劈柴声。
LONG );
	set("exits", ([
	        "north" : __DIR__"pianyuan", 
		]));
	setup();
}
void init()
{
	object me;
	me=this_player();
	if(me->query_temp("do_job1"))
	{
	remove_call_out("greeting");
	call_out("greeting",0,me);
        }
        add_action("do_chop","pi");
}
void greeting(object me)
{
	if(me->query_temp("do_job1"))
	message_vision("这里还有很多整木柴,快劈些柴火去厨房，正等着用呢！"+HIR+"（pi chai）\n"NOR,me);
}
int do_chop(string arg)
{
	object weapon;
	int i;
	i=(int)this_player()->query_temp("do_num");
	if(!this_player()->query_temp("do_job1"))
        return 0;
        if (!arg)
        return 0;
	if(arg!="chai")
	return notify_fail("你要劈什么？\n");
	if(!objectp(weapon=this_player()->query_temp("weapon"))
	||(string)weapon->query("id")!="chaidao")
        return notify_fail("你手上没有柴刀，怎么劈柴?\n");
        if(this_player()->is_busy())
        return notify_fail("你上个动作还没有完成，歇歇在做吧!\n");
        if(this_player()->query("jingli")<30)
        return notify_fail("你太累了，歇歇在做吧!\n");
        if(arg=="chai")
        {
        	if(i<1)
        	{
        	message_vision(RED"$N拿起柴刀用力的劈着柴火，一会已经累得满头大汗了。\n"NOR,this_player());
        	message_vision(HIY"只听“乓”的一声，一个不小心柴刀劈坏了。还好，柴火刚好劈完，$N满意的吁了一口气。\n"NOR,this_player());
        	tell_object(this_player(),HIR"快去厨房添柴火(add chai)。\n"NOR);
        	destruct(weapon);
        	this_player()->delete_temp("do_num");
        	this_player()->delete_temp("do_job1");
        	this_player()->set_temp("do_over_job1",1);
        	return 1;
                }
                else
                {
        	message_vision(RED"$N拿起柴刀用力的劈着柴火，一会已经累得满头大汗了。\n"NOR,this_player());
        	this_player()->start_busy(random(2));
        	this_player()->add("jingli",-random(15));
        	this_player()->add_temp("do_num",-1);
        	return 1;
                }
         }	
}        		

            



	


		
		


		
	
        
         

 

