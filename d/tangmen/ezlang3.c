//ezlang3.c		四川唐门—走廊

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这里是莲云阁东侧的走廊。北边一间小屋中有人轻声诵读着诗词
南边的小屋却寂静无声，也没有一个人出入，据说这是唐门的禁地，
没有掌门的手谕谁也不敢私自进入，东边飘来阵阵饭菜香味，让人食
指大动。
LONG);
	set("exits", ([
			"north" : __DIR__"eselfroom3",
//			"south" : __DIR__"mishi",
			"west" : __DIR__"ezlang2",
//			"east" : __DIR__"chufang",
	]));
	set("area", "蜀中");
	setup();
	replace_program(ROOM);
}