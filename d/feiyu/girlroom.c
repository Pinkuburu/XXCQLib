// Room: girlroom.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
//

inherit ROOM;

void create()
{
	set("short", "女弟子寝室");
	set("long", @LONG
这是一间宽敞的房间，室内仅有的几扇窗户却总拉着窗帘。屋内非常
整洁，隐隐透出一股清香。东墙边上有张台子，台子上点着香，墙上还挂
着一面铜镜，看来是女弟子们化妆用的。房间里剩下的就是几张大床和一
个大衣柜了。
LONG
	);

	set("no_fight", 1);

	set("sleep_room", 1);

	set("valid_startroom", 1);

	set("exits", ([
		"south" : __DIR__"xiaojing",
	]));

	setup();
	replace_program(ROOM);
}