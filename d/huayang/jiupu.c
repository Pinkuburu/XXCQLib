// Room: /city/zahuopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "小酒铺");
	set("long", @LONG
走进小酒馆，大概有七、八个人在一起喝酒聊天，仔细听听，原来就
是在聊剑庐最近的情况，另外有一个中年汉子独自坐在角落里，桌子上放
有一个包袱，一看就知道是个重兵器。
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"north" : __DIR__"hyroad4",
	]));

	set("objects", ([
	]));

	setup();
	replace_program(ROOM);
}