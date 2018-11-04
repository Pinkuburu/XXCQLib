// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "男弟子睡房");
	set("long", @LONG
这是一间昏暗的房间，房间仅有的一扇窗户还常年拉着帘。屋内是一
张大通铺，大约可以睡十几个人，借着隐隐的光亮可以看到床上已经睡了
几个人了。你没心思细观察，忙找了个地方上床躺下来。
LONG
	);

	set("no_fight", 1);

	set("sleep_room", 1);

	set("valid_startroom", 1);

	set("exits", ([
		"east" : __DIR__"qqlang_3",
	]));

	setup();
	replace_program(ROOM);
}