// Room: /city/dangpu.c
// YZC 1995/12/04 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "当铺");
	set("long", @LONG
这是京城唯一的一家当铺，因为在京城开当铺，不但要招揽好客户，
而且还要打点好上上下下的关系，这家当铺的刘老板能在京城开这家当铺
长达几十年，必然有后台支撑，至于是谁，就不得而知了。走进当铺，一
个五尺高的柜台挡在你的面前，柜台后坐着刘老板，一双精明的眼睛上上
下下打量着你。
LONG
	);
	set("valid_startroom", 1);
        set("no_steal", 1);
         set("no_fight", 1);
	set("objects", ([
		__DIR__"npc/liu1" : 1,
	]));

	set("exits", ([
		"west" : __DIR__"huangshanjie5",
	]));

	set("area", "汴梁");

	setup();
	replace_program(ROOM);
}
