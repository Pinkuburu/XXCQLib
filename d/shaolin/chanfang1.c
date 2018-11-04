// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "禅房");
	set("long", @LONG
这是一间昏暗的禅房，除了那长长的靠墙的大土炕，也就剩下墙上的
那个大大的佛字了。土炕的长度大约可以睡十几个人，借着隐隐的光亮可
以看到床上没有多少空地了。你没心思细观察，忙找了个地方躺了下来。
LONG
	);

	set("no_fight", 1);

	set("sleep_room", 1);

	set("valid_startroom", 1);

	set("exits", ([
		"south" : __DIR__"zoulang6",
	]));

	setup();
	replace_program(ROOM);
}