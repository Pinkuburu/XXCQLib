//dufang.c		四川唐门—毒房

#include <ansi.h>
#include <room.h>

inherit ROOM;

int do_putin(object me, object obj);

void create()
{
	set("short", "炼毒房");
	set("long", @LONG
这里是唐门的炼毒房。屋中没有什么摆设，只是靠墙摆着三个木
架，架子上摆满了药瓶药罐，屋子正中用上好的青石垒成了一个灶台
一个怕有千斤重的紫铜药炉重重的压在上面，让人奇怪的是两丈见方
的屋子里竟没有一个窗户。
LONG);
	set("exits", ([
			"southeast" : __DIR__"houroad4",
	]));
	set("objects", ([__DIR__"npc/tangdu" : 1,]));
	set("area", "蜀中");
	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_put","put");
}

int do_put(string arg)
{
	object obj, obj2, me, *inv;
	string item;
	int amount, i;

	me = this_player();

	if (!arg) return 0;

	if( sscanf(arg, "%s in yaolu", item) == 1 );
	else 
		return notify_fail("你要放什么东西？\n");

	if(sscanf(item, "%d %s", amount, item)==2)
	{
		if( !objectp(obj = present(item, me)) )	
			return notify_fail("你身上没有这样东西。\n");
		if( !obj->query_amount() )	
			return notify_fail( obj->name() + "不能被分开给人。\n");
		if( amount < 1 )
			return notify_fail("东西的数量至少是一个。\n");
		if( amount > obj->query_amount() ) 
			return notify_fail("你没有那么多的" + obj->name() + "。\n");
		else 
			if( amount == (int)obj->query_amount() )
				return do_putin(me, obj2);
			else
			{
				obj->set_amount( (int)obj->query_amount() - amount );
				obj2 = new(base_name(obj));
				obj2->set_amount(amount);
				if (do_putin(me, obj2))
					return 1;
				else
				{
					obj->set_amount((int)obj->query_amount() + amount);
					return 0;
				}
			}
	}

	if(arg=="all")
	{
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
		{
			do_putin(me, inv[i]);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("你身上没有这样东西。\n");
	return do_putin(me, obj);
}

int do_putin(object me, object obj)
{
	string tar, targ;
	int tarm;
	string *duwu = ({
		"","蜈蚣","毒蝎子","竹叶青","金环蛇","蝮蛇","千年毒王",
	});

	tar = (string)obj->query("name");
	tarm = (int)me->query_temp("duyao");
	targ = (string)duwu[tarm];

	printf("1%s1 == 1%s1 == %d/%d\n",tar,targ,tarm,sizeof(duwu));

	if ( !(int)me->query_temp("duyao"))
	{
		message_vision("唐毒一伸手打落了$N手上的" + obj->name() + "，叫到：“什么东西就往药炉里放。”\n", me);
		obj->move(this_object());
		return 1;
	}	

	if ( (tar == targ) && objectp(obj) )
	{
		message_vision("$N拿出" + obj->name() + "放进药炉。\n", me);
		destruct(obj);
		message_vision("唐毒对着$N点了点头，说到：“好，你干的很好，快去休息吧。”\n", me);
		me->delete_temp("tangmen");
		me->delete_temp("duyao");
		me->add("combat_exp", 150 + random(150));

//		if( (int)me->query("potential") > (int)me->query("learned_points"))
//			me->add("potential", ((int)me->query("learned_points") - (int)me->query("potential"))/2 );

		me->add("potential", 80 + random(30));
		return 1;
	}
	else
	{
		message_vision("唐毒一伸手打落了$N手上的" + obj->name() + "，叫到：“什么东西就往药炉里放。”\n快去找" + targ+ "回来！\n", me);
		obj->move(this_object());
//		destruct(obj);
		return 1;
	}
}