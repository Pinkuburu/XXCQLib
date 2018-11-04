// Room: eroad.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "小路");
        set ("long", @LONG
这是一条青石铺成的小路，两旁还种着一大片不知名的花草。从这里
再向东走就到飞鱼塘的东院了。向西一看，是一块大空地，好象有些人影
在晃动，那里就是东练武场了，你发现附近的人仿佛也都活跃起来。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"west" : __DIR__"dongwuchang",
		"east" : __DIR__"dongyuan",
       ]));

        set("outdoors", "feiyu");
        setup();
        replace_program(ROOM); 
}

