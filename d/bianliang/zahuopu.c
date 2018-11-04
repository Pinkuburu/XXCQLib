// Room: /city/zahuopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "杂货铺");
	set("long", @LONG
这是京城最大的一家杂货铺，大箱小箱堆满了一地，都是一些日常用
品。韦掌柜懒洋洋地躺在一只躺椅上，招呼着过往行人。据说私底下他也
卖一些贵重的东西。
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"west" : __DIR__"nandajie2",
	]));

	set("objects", ([
		__DIR__"npc/wei": 1,
	]));

	set("area", "汴梁");

	setup();
	replace_program(ROOM);
}