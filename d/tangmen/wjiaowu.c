//wjiaowu.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "西较武场");
	set("long", @LONG
这是唐门的西较武场。一片开阔平坦的空地，最适合比试武功。
不要看平日冷冷清清，唐门定期举行的比武大会，有一半的赛事在这
里进行。较场西侧，排放了几个兵器架。较场的东面，并排着三个看
台，比赛时候那惊天动地的喝彩声，全都来自这里。
LONG);	
	set("no_steal", "1");
	set("no_fight", "1");
	set("exits", ([
		"east" : __DIR__"wkantai2",
	]));
	setup();
	replace_program(ROOM);
}