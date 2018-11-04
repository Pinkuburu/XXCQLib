//shuige2.c		四川唐门—亭榭水阁

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "亭榭水阁");
	set("long", @LONG
这里是莲藕小筑的亭榭水阁。这里与莲藕小筑连为一体，同样是
古玉色的建筑。水阁四壁上绘着各色的山水鱼虫，这里再往前就是莲
云阁了！
LONG);
	set("exits", ([
		"north" : __DIR__"lianyunge",
		"south" : __DIR__"shuige1",
	]));
	set("area", "蜀中");
	setup();
	replace_program(ROOM);
}