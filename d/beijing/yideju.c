// Room: /city/yideju.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "一得居");
	set("long", @LONG
	一得居是一家不大的酒铺，由于地理原因，又加上价格便宜，所以这里常
聚集着劳碌一天的穷人们，一壶酒，一碟花生豆，大家谈天说地，来度过一天最快
乐的时光。这里的环境比较差，但如果你不介意，那这里倒是一个打听消息和消磨
时光的好地方。
LONG
	);
	set("resource/water", 1);

	set("valid_startroom", 1);
	set("exits", ([
		"north" : __DIR__"shalan-e2",
	]));

	set("objects", ([
		__DIR__"npc/xiaoer3" : 1,
	]));

	setup();
	replace_program(ROOM);
}

