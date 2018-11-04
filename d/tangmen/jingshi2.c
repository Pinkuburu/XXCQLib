//jingshi2.c		四川唐门—静室

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "静室");
	set("long", @LONG
这是一间静室。这里是唐门弟子吐纳、打坐的地方，这里非常安
静，没有一丝声音。屋中没有任何摆设，只是在地上扔着十几个蒲团
有几名弟子正盘坐在上面用心练功。
LONG);
	set("no_steal", "1");
	set("no_fight", "1");
	set("exits", ([
			"north" : __DIR__"nzlangw2",
	]));
	set("area", "蜀中");
	setup();
	replace_program(ROOM);
}