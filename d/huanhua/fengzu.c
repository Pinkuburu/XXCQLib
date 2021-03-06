// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "飞凤堂");
	set("long", @LONG
走进飞凤堂，你会发现这里虽然没有多么的豪华，但处处透出一种清
新、淡雅，让人感到舒适、恰意，十余盆丁香花使得空气中弥漫着淡淡的
香气。十几名女子站列两旁，一个个英姿勃发，巾帼不让须眉。一个红衣
女子站在堂前分派着工作。
LONG
	);

	set("valid_startroom", 1);
	set("exits", ([
		"east" : __DIR__"northyuan",
	]));

        set("objects", ([
		"/kungfu/class/huanhua/hua" : 1,
	]));

	setup();
	replace_program(ROOM);
}