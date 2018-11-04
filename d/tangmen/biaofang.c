//biaofang.c		四川唐门—镖房

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "暗器房");
	set("long", @LONG
这里是唐门的暗器房。一踏进屋门便感到一股热浪迎面扑来，屋
子正中的几个巨大风箱格外夺目，几个汉子正卖力的拉动着，将火焰
激起丈于高，唐门的制镖高手唐镖正在全神贯注的打造着什么。
LONG);
	set("exits", ([
			"southeast" : __DIR__"houroad3",
	]));
	set("objects", ([__DIR__"npc/tangbiao" : 1,]));
	set("area", "蜀中");
	setup();
	replace_program(ROOM);
}