// neitang.c 内堂
// lks设计、编程

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","内堂");
	set("long",
	"这里就是发梦二党之温宅的大首领--温梦成工作、发号施令的地方。
由于最近京城里的情况风云变幻，两大势力正在勾心斗角。大有一触即发
之势，所以这里也显得格外忙碌，几乎天天都要开会，讨论局势。\n"
     	);
     	set("valid_startroom",1);
	set("exits",([
     		"west" : __DIR__"zoulang2",
     	]));
     	set("objects",([
     		__DIR__"npc/wenmengcheng" : 1,
     	]));
     	setup();
     	replace_program(ROOM);
}


     	