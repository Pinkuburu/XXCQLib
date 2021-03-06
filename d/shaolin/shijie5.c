// Room: /d/shaolin/shijie5.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
一挂巨大的瀑布白龙出霄般横越山间，水气已浓得仿佛可以滴下水珠
儿来。山峦间升起薄薄的青雾，凝聚不散。哗哗的水声震耳欲聋。石阶上
满是水渍，走上去滑得可以让人打跌。
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"southdown" : __DIR__"shijie4",
		"northup" : __DIR__"shijie6",
	]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");
	setup();
}

int valid_leave(object me, string dir)
{
	me = this_player();

	if (( present("shui tong", this_player())) && dir == "northup")
	{
		if (me->query("jingli")<15)
			return notify_fail("提着大水桶，你已经累的走不动道了。\n");
		me->add("jingli",-10);
		me->improve_skill("dodge",10+random(5));
		me->start_busy(1);
	}

	return ::valid_leave(me, dir);
}
