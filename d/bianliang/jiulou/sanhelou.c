// Room: /city/sanhelou.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "叁合楼");
	set("long", @LONG
叁合楼是汴梁城酒楼论年代则是最古老的一家，它坐落在内城，是许
多公子官员常常光顾的地方，这里也是京城几大帮派谈判常选的地方。楼
下布置简易，顾客多是匆匆的行人，买点包子、鸡腿、米酒就赶路去了。
楼上是雅座。
LONG
	);
	set("no_fight",1);
	set("valid_startroom", 1);
	set("exits", ([
		"up" : __DIR__"sanhelou2",
		"east" : "/d/bianliang/huangshanjie5",
	]));

	set("objects", ([
		__DIR__"xiaoer2" : 1,
	]));

	setup();
	replace_program(ROOM);
}
