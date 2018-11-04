//shandao2.c		四川唐门—后山山道

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
这里是通向山顶的小道。奇陡无比，一不小心就会摔下去，两边
是高耸入云的参天大树，林中传来野兽的撕咬声，令人毛骨悚然、不
寒而立，你全神贯注生怕有野兽扑来。
LONG);
	set("exits", ([
			"southwest" : __DIR__"shandao1",
			"eastup" : __DIR__"shandao3",
	]));
	set("area", "蜀中");
	set("objects", ([__DIR__"npc/deer" : 1,__DIR__"npc/yetu" : 1,]));
	setup();
	replace_program(ROOM);
}