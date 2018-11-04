// xixiangfang.c 西厢房
// mlf设计,lks编程

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","西厢房");
        set("long",
"这里是花府的西厢房，房间里除了书还是书，只有墙上挂者着一件兵
器，那是扫眉才子宋展眉的随身兵器，显示出在这里的是个文武双全的人
物。此刻他就坐在书桌旁。\n"
	);
	set("valid_startroom",1);
	set("exits",([
		"south" : __DIR__"xiting",
	]));
	set("objects",([
		__DIR__"npc/song" : 1,
	]));
	setup();
	replace_program(ROOM);
}
