// zaotang.c  by winder

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "华清池大堂");
	set("long", @LONG
华清池百年老店气派就是不同凡响，大堂里一片素洁，正中一块匾额
是宋太宗亲笔题的“地华天清”四个大字。在大堂里设有二十余把躺椅，
供人们休息，一个小二跑来跑去的为客人们服务。大堂左右各有一道门，
门上的布帘子上分别写有“男”、“女”的字样。
LONG);	
	set("valid_startroom",1);

	set("exits", ([
		"west" : __DIR__"huangshanjie3",
		"north" : __DIR__"boywash",
		"south" : __DIR__"girlwash",
	]));

	set("objects", ([
		__DIR__"npc/chunhua" : 1,
	]));

	set("area", "汴梁");

	setup();
}

int valid_leave(object me, string dir)
{
	me = this_player();

	if (  (dir == "north" )&& (me->query("gender") == "女性" )) 
	{
        	if(objectp(present("meng chunhua", environment(me))))
			return notify_fail("孟春花伸手拦住你道：这边是男部，那边才是你该进的地方。\n");
	}

	if (  (dir == "south" )&& (me->query("gender") == "男性" )) 
	{
        	if(objectp(present("meng chunhua", environment(me))))
			return notify_fail("孟春花用疑惑的眼光打量着你道：这边是女部，你什么意思？\n");
	}

	return ::valid_leave(me, dir);
}