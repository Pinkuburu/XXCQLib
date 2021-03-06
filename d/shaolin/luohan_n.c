// Room: /d/shaolin/banruo1.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "罗汉堂偏殿");
	set("long", @LONG
这是罗汉堂北偏殿，是一间极为简陋的禅房。环视四周，除了几幅佛
竭外，室内空荡荡地别无他物。西面是少林功夫房之一的进武房，地上摆
放着一个破烂且发黑的黄布蒲团，一位须发花白的老僧正在坐在上面闭目
入定，他就是负责看管进武房的天空。
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"south" : __DIR__"luohan",
		"east" : __DIR__"kfroom_2",
	]));

	set("objects",([
		"/kungfu/class/shaolin/tiankong" : 1,
	]));

	setup();

}

void init()
{
	object me = this_player();

	if (me->query_temp("kfroom_2"))
	{
		me->delete_temp("kfroom_2");
		environment(me)->delete_temp("kfroom_2");
	}
}

int valid_leave(object me, string dir)
{
	if( !me->query_temp("kfroom_2"))
	{
		if (dir == "east")
		{
			return notify_fail("进武房机关重重，没有天空的允许谁也进不去。\n");
		}
	}
	return ::valid_leave(me, dir);
}