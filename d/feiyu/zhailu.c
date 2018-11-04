// Room: zhailu.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "小径");
        set ("long", @LONG
这是一条很窄的泥路，你走得有些不舒服。从这里再向北走几步就到
了飞鱼塘的西院了。这条路上一个人也没有，据说这里在晚上有人见到了
几个黑影一闪而过。所以现在已经很少人来这里了。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"north" : __DIR__"xiyuan",
		"south" : __DIR__"xiaowu",
       ]));

        set("outdoors", "feiyu");
        setup();
        
}

int valid_leave(object me, string dir)
{
        me=this_player();

        if (  ((dir == "south") )
                && ( present("jian", this_player())
                || present("dao", this_player()) ))
        {
	        message_vision("你发现这小屋有些古怪，你的武器全都粘在门上拿不下来了！看来你要先放下武器了。\n", me);
        	return notify_fail("\n");
        }
        return ::valid_leave(me, dir);
}

