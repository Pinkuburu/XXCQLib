// Room: 小径
// Date: by godzilla 1999.11.18

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "小径");
	set("long", @LONG
一条曲曲折折用鹅卵石铺成的小径，路两旁绿树成荫，走在石路
上，啪嗒啪嗒的发出清脆的响声，这里已经没有路了。不过好象有五
棵树似乎非常特别，你可以(move)试试。
LONG );
        set("outdoors", "tianyu");
	set("exits", ([
	        "east" : __DIR__"xiaojing1", 
		]));
	setup();
	
}
void init()
{
	object me=this_player();
        if(me->query("kar")>12+random(50)&&me->query("family/family_name")=="天羽派")
        {
        	call_out("fang_per",1,me);
        }
        add_action("do_climb","move");
	
}
void fang_per(object me)
{
           if(me->query("lingwu_perform"))
          {
                 return 0;
          }  
    tell_object(me,HIG"树上的积雪已经融化，阳光照了进来你猛然发现第四棵可有移动的痕迹
你可以试试(move 第四棵树)。\n"NOR);
        me->set_temp("find/铁帜",1);
}
int do_climb(string arg)
{
	object me=this_player();
	if(!arg||arg=="")
	return notify_fail("错误指令！应该输入(move xxxx)，例如(move 第一棵树)\n");
       if(me->query("jingli")<110)
     return notify_fail("你现在太累了。\n");
	switch(arg)
        {
        	case "第一棵树":
        	case "第二棵树":
        	case "第三棵树":
        	case "第五棵树":
        	message_vision("$N使出吃奶的力气移动树干，良久.....只是树叶动了几下，树干却纹丝不动，你已经累得精疲力尽了。\n",me);
                me->add("jingli",-200);
                return 1;
                break;
                case "第四棵树":
                if(!me->query_temp("find/铁帜"))
		{
			message_vision("$N使出吃奶的力气移动树干，良久.....只是树叶动了几下，树干却纹丝不动，你已经累得精疲力尽了。\n",me);
                        me->add("jingli",-200);
                        return 1;
		}
		message_vision("$N使出吃奶的力气移动树干，不一会树干缓缓的移动留出了一个缝隙，$N赶忙钻了过去。\n",me);
		me->move(__DIR__"treeup");
		me->set_temp("find/铁帜",0);
		return 1;
	        break;

             }
}				
