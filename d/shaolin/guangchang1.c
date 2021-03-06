// Room: /d/shaolin/guangchang1.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
    set("short", "山门广场");
    set("long", @LONG
这里是少林寺前的广场，整个广场由大块的青石铺成，极为平坦。但
因年代久远，都有些破损。丛丛小草从石板的缝隙中长了出来。广场周围
都是密密的松树林，四角上各放了几块石碑，字迹都甚为模糊。正前方黄
墙碧瓦，飞檐翘檩，正中一道二丈来宽，三丈来高的朱红杉木包铜大门。
上方一块大匾，龙飞凤舞地书着『少林寺』三个大字。寺前三三两两的站
着几个僧人。
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"south" : __DIR__"shijie11",
		"north" : __DIR__"smdian",
	]));

	set("outdoors", "shaolin");
	set("objects",([
        	"/kungfu/class/shaolin/tongzhi" : 1,
		"/kungfu/class/shaolin/tonghui" : 1,
	]));
	setup();
	"/clone/board/shaolin_b"->foo();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "少林派" ) && dir == "north")
	{
		if (me->query("shen") < 0)
		{
			if(objectp(present("tong zhi", environment(me))))
				return notify_fail("铜智双臂一振，横眉怒目地说道：你等邪魔外道，还不给我滚开！\n以后再敢走近少林一步，我立时就打断你们的狗腿！\n");
			else if(objectp(present("tong hui", environment(me))))
				return notify_fail("铜慧双臂一振，横眉怒目地说道：你等邪魔外道，还不给我滚开！\n以后再敢走近少林一步，我立时就打断你们的狗腿！\n");
		}
		if (me->query("gender") == "女性")
		{
			if(objectp(present("tong zhi", environment(me))))
			{
	        		return notify_fail("铜智合十为礼，说道：这位女施主还是请回罢，本寺从不接待女客。\n");
			}
			else if(objectp(present("tong hui", environment(me))))
			{
				return notify_fail("铜慧合十为礼，说道：这位女施主还是请回罢，本寺从不接待女客。\n");
			}
		}	
		if(objectp(present("tong zhi", environment(me))))
		{
	       		return notify_fail("铜智合十为礼，说道：这位施主请回罢，本寺不接待俗人。\n");
		}
		else if(objectp(present("tong hui", environment(me))))
		{
			return notify_fail("铜慧合十为礼，说道：这位施主请回罢，本寺不接待俗人。\n");
		}
	}

	return ::valid_leave(me, dir);
}