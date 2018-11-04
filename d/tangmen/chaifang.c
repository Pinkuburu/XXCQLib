//chaifang.c		四川唐门—柴房

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "柴房");
	set("long", @LONG
这里是后院的柴房，屋中堆满了劈好的柴火，满屋都是木材的香
味，在山也似的柴堆旁一扇小门通向后山，听说那里出没着豺狼虎豹
和蜈蚣蛇蝎，工夫不够高可不要乱跑呀！
LONG);
	set("exits", ([
			"west" : __DIR__"chufang",
			"south" : __DIR__"nzlange1",
			"north" : __DIR__"exiaolu1",
	]));
//	create_door("northeast","木门","southwest",DOOR_CLOSED);
	set("objects", ([__DIR__"npc/tangbukun" : 1,]));
	set("area", "蜀中");
	setup();
	replace_program(ROOM);
}