// Room: /d/gvmt/jianyu_do.c
// Date: YZC 96/02/06

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "监狱大门");
	set("long", @LONG
这里是监狱大门，门内黑沉沉的，很是阴森恐怖，不时传来微弱
的呻吟声，隐约的似乎还有皮鞭拷打的声音。直让你真想回头就
往南边的大门外跑去。
LONG
	);
	set("exits",([
		"south":"/d/bianliang/guangming",
	]));
	set("objects",([
		__DIR__"npc/yuzu":1,
	]));
	setup();
	replace_program(ROOM);
}
