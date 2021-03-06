// Room: /welcome/yaopu.c
//By adx @ CuteRabbit 15:57 99-5-18

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",WHT"神雪药铺"NOR);
	set("long",
"这是一家药铺，一股浓浓的药味让你几欲窒息，那是从药柜上的几百个小\n"+
"抽屉里散发出来的。一名小伙计站在柜台后招呼着顾客。墙上贴着一张\n"+
"广告"+HIM"（guanggao）"NOR+"你首先应当看看。\n"
 );
	set("item_desc", ([
		"guanggao" : "你可以用"+HIC"list"NOR+"查看本店出售的药品"+
			     "用"+HIC"buy"NOR+"买药品。\n"+
			     "另外本店急需帮工，请向山主打听。\n\n",
	]));
	set("objects", ([
		__DIR__"npc/huoji" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"nanlang2",
	]));
	set("no_fight", 1);
	setup();
}

void init()
{
           add_action("do_job","chong");
}
int do_job(string arg)
{
        object *inv;
        object me;
         int i, jingli;
	me = this_player();
	jingli = ( random(me->query("con"))/3 );
	inv = all_inventory(me);
	if (jingli <= 0)
		jingli = 5;

	if (me->query("jingli")<=10) {
	message_vision ("你没有气力了，先去休息室睡一下吧！"+HIC"(sleep)\n"NOR, me );
        return 1;
	}
	   //判断是否wield了工具
	if( (string)(inv[i]->query("id"))=="shichu" && 
		(int) inv[i]->query("equipped") ) 
	{
		if( !arg || arg!="草药" )
			{return notify_fail ("你要舂什么？\n");
		}
		else {
			me->add_temp("wancheng", jingli);
			me->add("jingli", -jingli);
			me->add("combat_exp", jingli);
			me->add("potential", (jingli/2));
			message_vision ("$N拿起石杵用力的砸着草药！\n", me );
			if (me->query_temp("wancheng") >= 100)
			{
				me->set_temp("renwu",100);   //设100表示完成任务
				return notify_fail (WHT"你可以回去复命了！(ask moto about ok)\n"NOR);
				}
			}
	}
	else {
		return notify_fail ("你空手怎么舂草药？拿拳头砸吗！\n");
		}
        return 1;
}
int valid_leave(object me, string dir)
{
         if ( (dir == "east") &&
		(me->query("wancheng") >= 100) )
	{
		if ( !present("shichu", me) ) {return 1;}
			message_vision ("$N放下手中的石杵。\n", me);
			destruct(present("shichu", me));
	}
	return ::valid_leave(me, dir);
}
