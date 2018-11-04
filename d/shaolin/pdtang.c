// Room: /d/shaolin/qfdian.c
// Date: YZC 96/01/19

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "普渡堂");
	set("long", @LONG
这是就是普渡堂。大堂内很是素洁，佛堂的正中挂有黄锦黑字的“放
下屠刀，立地成佛”和“苦海无边，回头是岸”两幅大字。堂内摆有二十
余个黄埔团，供僧人在此跪坐听经。少林寺豹象木蝶大师在此讲经。
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"southdown" : __DIR__"guangchang3",
	]));
	set("objects",([
		"/kungfu/class/shaolin/baoxiang" : 1,
	]));
	setup();
	replace_program(ROOM);
}

