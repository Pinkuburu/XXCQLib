// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "鹰翔堂");
	set("long", @LONG
走进堂来，就看到堂前挂一幅人高的水墨画“鹰击长空”。堂内放有
十余张桌案，每个案前都有人在写着什么，这里没有其他堂的肃穆，更多
的是一份忙碌。不时有弟子匆匆来，匆匆去。
LONG
	);

	set("valid_startroom", 1);
	set("exits", ([
		"west" : __DIR__"northyuan",
	]));

        set("objects", ([
		"/kungfu/class/huanhua/song" : 1,
	]));

	setup();
	replace_program(ROOM);
}