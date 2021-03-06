// Room: /d/shaolin/shijie4.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "山涧小溪");
	set("long", @LONG
水声越来越大，山间充满了浓浓的水气。石阶上，断裂的山隙中，都
流出一道道细细的泉水，汇成一股澄碧的小溪，向山下蜿蜒流去。周围绿
意荡漾，鸟语鹦声，如置身仙境，经常有山上下来的僧人提着水桶到这里
打水。
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"northup" : __DIR__"shijie5",
		"eastdown" : __DIR__"shijie3",
	]));
	set("sljob",1);
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
