// dongxiangfang.c 东厢房
// mlf设计,lks编程

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","东厢房");
        set("long",
"这里也是花府的帐房所在，花府每日钱财出入的帐目都在这里。房里
四周是一些黑色的柜子，不知放了些什么。书桌（table）上堆着小山一
样的帐簿，管家唐一独正在忙碌的写着什么。 发梦二党的弟子可以在这里
领到不同的薪水和任务。\n"
	);
	set("exits",([
		"north" : __DIR__"dongting",
	]));
	set("item_desc", ([
		"table" : "桌上杂乱的堆着帐簿。\n",
	]));
	set("objects",([
		__DIR__"npc/tang" : 1,
	]));
	set("valid_startroom",1);
	set("book_count",1);
	setup();
}

void init()
{
	add_action("do_move","move");
}

int do_move(string arg)
{
	object ob, me= this_player();
	object where=environment(me);
	if (arg!="zhang bu" && arg!="bu") return 0;
	if (!where->query("book_count"))
		return notify_fail("帐簿已经被人翻的乱七八糟。\n");
	ob = new(__DIR__"obj/strike-book");
	ob->move(where);
	message_vision("只听见“啪”的一声，一本书掉了下来。\n",me);
	set("book_count",0);
	return 1;
}
		
	
