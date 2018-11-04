// Room: shulin1.c
// Created by Zeus 1999.4.8
// Modified by Zeus 1999.6.10
// 
// 
#include <ansi.h>

inherit ROOM;
void init();
int do_zhao(string);

void create ()
{
        set ("short", "树林");
        set ("long", @LONG
这里是茂密的树林，由于树枝的茂密遮住了阳光，觉得有些阴森恐怖
。不时有两只野兔跑过你身边。向西走还是一片树林，向南走是条非常陡
峭的山径。
LONG);
        set("area","岭南");
        set("outdoors", "wenjia");
        set("valid_startroom", 1);

        set("objects", ([
                __DIR__"npc/yetu" : 1,
        ]));

        set("exits", ([
                "southup" : __DIR__"shanjing2",
                "west" : __DIR__"shulin2",
        ]));

        setup();
}

void init()
{
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{

        object me;
        object chifan;

        if (!arg || arg != "up" )
        {
                return notify_fail("你要爬什么?\n");	
        }
		
        me = this_player();	
	 	
        if( !me->query_temp("taskxiao/given"))
        {
                return notify_fail("你无不无聊，这么喜欢爬?\n");	
        }

        if ( me->query_skill("dodge",1)>50)
        {
                message_vision("只见$N轻轻将脚在树脚上一掂，身子如燕飞，上了树干。\n",me);
                me->move(__DIR__"task_xiao/shushang");
        }
        else if (me->query_skill("dodge",1)>25)
        {
                message_vision("只见$双手在树干上一抓，非常笨拙的爬上树干。\n",me);
                me->move(__DIR__"task_xiao/shushang");
        }
        else
                return notify_fail("你怎么用力都没办法爬上树。\n");	
        
        return 1;
}
