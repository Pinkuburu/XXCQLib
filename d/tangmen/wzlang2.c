//wzlang2.c		四川唐门—走廊

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这里是莲云阁西侧的走廊。这里较别的地方又安静了许多，原来
两边是唐门弟子修炼内功、心法的静室，没有人敢在这里吵闹。从这
里向西通向休息室，向东就回到了练功场。
LONG);
	set("exits", ([
			"east" : __DIR__"wzlang1",
			"west" : __DIR__"wzlang3",
			"north" : __DIR__"wselfroom2",
//			"north" : __DIR__"jingshi1",
//			"south" : __DIR__"jingshi2",
	]));
	set("area", "蜀中");
	setup();
	replace_program(ROOM);
}