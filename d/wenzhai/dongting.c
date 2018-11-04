// dongting.c 东厅
// mlf设计,lks编程

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","东厅");
	set("long",
	"这里虽然是偏厅，但是已经被用来作为温府弟子的练功场了，温府的
入门弟子就是在这里练习基本功的，并且温府的高手“温门十石”也经常
来这里指点弟子的武功，所以这里没有桌椅之类的摆设。\n"NOR
     	);
     	set("valid_startroom",1);
	set("exits",([
     		"east"  : __DIR__"dongxiangfang",
     		"west"  : __DIR__"dating",
     		"north" : __DIR__"wuqiku",
     	]));
     	setup();
     	replace_program(ROOM);
}
