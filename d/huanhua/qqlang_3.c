// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "七曲廊");
	set("long", @LONG
七曲廊走到这里已经很是寂静了，大概是因为浣花弟子的睡房就在西
面的缘故吧。本来就很少人经过，偶尔有人经过也是默不作声。沿走廊再
往南可以到浣花重地见天洞。
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"west" : __DIR__"boyroom",
		"northeast" : __DIR__"qqlang_2",
		"south" : __DIR__"jiashan",
	]));

        set("objects", ([
		__DIR__"npc/shulin" : 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;

	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "浣花剑派" || myfam["generation"] > 4 ) && dir == "south" )
	{
        	if(objectp(present("shu lin", environment(me))))
        		return notify_fail("树林伸手拦住你厉声道：浣花重地，不得乱闯，还不快快离开！\n");
	}

	if (me->query("gender")=="女性" && dir == "west")
	{
		return notify_fail("你一个女孩子，到男弟子休息室做什么？\n");
	}

	return ::valid_leave(me, dir);
}