// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "女弟子睡房");
	set("long", @LONG
这是一间昏暗的房间，房间仅有的一扇窗户还常年拉着帘。屋内很是
整洁，隐隐透出一股清香。通铺的上有几个女弟子和衣而睡，你没心思细
观察，忙找了个地方上床躺下来。
LONG
	);

	set("no_fight", 1);

	set("sleep_room", 1);

	set("valid_startroom", 1);

	set("exits", ([
		"east" : __DIR__"jqlang_3",
	]));

	setup();
	replace_program(ROOM);
}