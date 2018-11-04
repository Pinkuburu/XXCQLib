//wrukou.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "西较武场入口");
	set("long", @LONG
这是唐门的西较武场入口。门口上面块一金漆牌匾，“西较武场”
几个大字写得孔武有力，气势逼人，仿佛是几件随时可以横空而出的暗
器，记载了唐门战史的辉煌。这里的西面，是西较武场的看台，东面是
一条青石小路。
LONG);	
	set("no_steal", "1");
	set("no_fight", "1");
	set("exits", ([
		"east" : __DIR__"nzlangn1",
		"west" : __DIR__"wkantai2",
	]));
	setup();
	replace_program(ROOM);
}