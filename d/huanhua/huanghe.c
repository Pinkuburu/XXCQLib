// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "黄河小轩");
	set("long", @LONG
走进黄河小轩，你大气也不敢喘一下，因为浣花剑派的现任掌门萧西
楼就坐在书案后面奋笔疾书，不时的站起来踱步、沉思。左右靠墙立着两
座两人高的书架，上面摆满了各种书籍，而后墙上则挂着一柄长剑。
LONG
	);


	set("exits", ([
"south" : __DIR__"menqian",
	]));

        set("objects", ([
		"/kungfu/class/huanhua/xilou" : 1,
	]));

	setup();
	replace_program(ROOM);
}
