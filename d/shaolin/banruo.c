// Room: /d/shaolin/banruo1.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "般若堂");
	set("long", @LONG
般若堂、罗汉堂肩负为少林培养武僧的责任，其中你所在的般若堂掌
管少林功夫房中的始武、益武、穷武三房，般若堂首座地极大师功夫已臻
化景，是少林七大高僧之一，般若堂的西面就是益武房，坐在地极大师下
手的就是负责看管益武房的天刑。
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"north" : __DIR__"banruo_n",
		"west" : __DIR__"kfroom_3",
		"south" : __DIR__"banruo_s",
		"east" :__DIR__"wuchang6",
	]));

	set("objects",([
		"/kungfu/class/shaolin/tianxing" : 1,
		"/kungfu/class/shaolin/diji" : 1,
	]));

	setup();

}

void init()
{
	object me = this_player();

	if (me->query_temp("kfroom_3"))
	{
		me->delete_temp("kfroom_3");
		environment(me)->delete_temp("kfroom_3");
	}
}

int valid_leave(object me, string dir)
{
	if( !me->query_temp("kfroom_3"))
	{
		if (dir == "west")
		{
			return notify_fail("益武房机关重重，没有天刑的允许谁也进不去。\n");
		}
	}
	return ::valid_leave(me, dir);
}