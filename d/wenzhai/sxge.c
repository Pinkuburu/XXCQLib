// sxge.c 书香阁
// mlf设计,lks编程

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","书香阁");
	set("long",
	"这里迎面而来的就是一股书香味，正面墙上一块原木所制牌匾，红底
黑字“书香阁”。四周墙壁被砌成书架，井然有序的放满了书，其中也有
不少武学入门的书籍。“温门十石”中的清谋石在这里负责管理，你可以
向他要书。\n"NOR
     	);
     	set("valid_startroom",1);
	set("exits",([
     		"east" : __DIR__"huayuan",
     	]));
     	set("objects",([
     		__DIR__"npc/qing" : 1,
     	]));
	setup();
	replace_program(ROOM);
}


	
     	