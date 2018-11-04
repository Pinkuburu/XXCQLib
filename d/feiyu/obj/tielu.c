// Item tielu.c  
// Modified by Atlus Oct.14.1999
// 

inherit ITEM;

void create()
{
        set_name( "炉子",({ "lu zi"}));
        set_weight(500000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long","这是一个炉子。\n");
                set("value", 50);
                set("material", "iron");
        }
}

void init()
{
        add_action("do_ran","ran");
        add_action("do_da","da");
        add_action("do_fang","fang");
        add_action("do_la","la");    
}

int do_la(string arg)
{  
        object me=this_player();

        if (!arg || arg!="风箱" ) {
               return notify_fail("你要拉什么？\n");
       }
        
		if( (int)me->query("neili") > 100 )
	   {
		return notify_fail("用内力燃炉不好吗?何必浪费气力呢！\n");
        }

        if ( me->query_temp("fy_task_datie/ran"))
	    {
               return notify_fail("这个炉子已经燃起来了\n");
		}
        
		me->add("qi", -50);
        message_vision("$N用力拉风箱,使炉子点起了火\n", me);
		me->set_temp("fy_task_datie/ran",1);
		return 1;

}

int do_ran(string arg)
{
		object me=this_player();

       if (!arg || arg!="lu zi" ) {
               return notify_fail("你要燃什么？\n");
       }

		if( (int)me->query("neili") < 100 )
	   {
		return notify_fail("你现在的内力不足！\n");
        }
		
		if ( me->query_temp("fy_task_datie/ran"))
	    {
               return notify_fail("这个炉子已经燃起来了\n");
		}
		
		me->add("neili", -100);
        message_vision("$N用内力将炉子点火\n", me);
		me->set_temp("fy_task_datie/ran",1);
		return 1;

}
int do_da(string arg)
{
		object me=this_player();
		object ob;

       if (!arg || arg!="铁块" ) {
               return notify_fail("你要打什么？\n");
       }

		if (!me->query_temp("fy_task_datie/given_hammer") )
		{
                message_vision("请$N先到材料房去借个铁锤再来吧!\n",me);
                return 1;
		}
		if  ( !present("hammer", this_player()))
        {
		     message_vision("请$N先去借个铁锤再来吧!\n",me);
			 return 1;
	    }
		if ( me->query_temp("fy_task_datie/done"))
		{
               return notify_fail("这个铁块已经打好了。\n");
		}
		
		if ( !me->query_temp("fy_task_datie/ran"))
		{
               return notify_fail("炉子没有热起来,怎么能打铁?\n");
		}

		if ( me->query_temp("fy_task_datie/has_put"))
		{
               return notify_fail("你已经把铁块放进炉去了。\n");
		}
        if (me->query("qi")<20)
               return notify_fail("你现在太累了，休息一下再来吧!\n");

		if ( !me->query_temp("fy_task_datie/hot"))
		{
               return notify_fail("铁块还是不够热，怎么打?\n");
		}

		if ( (time()-me->query_temp("fy_task_datie/tiere_time") ) > 20)
		{
				me->delete_temp("fy_task_datie/hot");
			   return notify_fail("铁块慢慢的冷了，需要再加热一下。\n");
		}

		if ( me->query_temp("fy_task_datie/da_time")<=0 )
		{
			message_vision("$N将铁块打好了,制成了一件武器!\n", me);
			me->set_temp("fy_task_datie/done",1);
			ob=new(__DIR__"wuqi");
			ob->move(me);
			return 1;
		}
		me->add("qi", (-1)*( random(10) + 10) );
		message_vision("$N抡起铁锤,一下打在烧红的铁块上.\n", me);

		if ( random(10) +me->query("str") > 25 )
		{
			message_vision("$N将铁块慢慢打出形状\n", me);
			me->add_temp("fy_task_datie/da_time",-1);
		} else 
		message_vision("$N将铁块打歪了,只好再加热重打!\n", me);
		return 1;

}
int do_fang (string arg)
{
		object me=this_player();

		if ( !me->query_temp("fy_task_datie/ran"))
		{
               return notify_fail("炉子没有热，放进去有什么用。\n");
		}

	   if (!arg || arg!="铁块" ) {
               return notify_fail("你要放什么？\n");
       }

		if ( me->query_temp("fy_task_datie/hot"))
		{
               return notify_fail("这个铁块还是热的,不需加热。\n");
		}
	
		if ( me->query_temp("fy_task_datie/has_put"))
		{
               return notify_fail("你已经把铁块放进去了。\n");
		}

        message_vision("$N将铁块放入炉子中加热。\n", me);
		me->set_temp("fy_task_datie/has_put",1);
		call_out("hot_ok", 10);
		return 1;
}
int hot_ok()
{
		object tiekuai;
		object me=this_player();
		tiekuai=new(__DIR__"tiekuai");

		message_vision("铁匠将一块铁块放在$N面前。\n", me);
		me->set_temp("fy_task_datie/hot",1);
        me->set_temp("fy_task_datie/tiere_time",time());
        me->delete_temp("fy_task_datie/has_put");
		return 1;
}
