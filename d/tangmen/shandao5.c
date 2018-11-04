//shandao5.c		四川唐门—后山山道

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
这里是通向山顶的小道。奇陡无比，一不小心就会摔下去，两边
是高耸入云的参天大树，越接近山顶温度越低了，你扣紧衣襟仍感到
寒气逼人，再向上就是裂星崖了。
LONG);
	set("exits", ([
			"southdown" : __DIR__"shandao4",
			"northup" : __DIR__"liexingya",
	]));
	set("area", "蜀中");
	set("objects", ([__DIR__"npc/duwang" : 1,__DIR__"npc/wolf" : 1,]));
	setup();
	replace_program(ROOM);
}