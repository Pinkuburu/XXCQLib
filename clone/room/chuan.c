// Room: /city/kefang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "乌篷船内");
	set("long", @LONG
你现在在一辆乌蓬船内，船里摆有一张小桌子，上面散乱的摆着一些
吃的喝的，乌篷的最里面铺有被褥，困了也可以休息休息，隐隐的可以听
到河水的声音，不知道什么时候才可以到。
LONG
	);

	setup();
}