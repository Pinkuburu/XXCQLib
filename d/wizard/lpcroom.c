// Room: /d/wizard/wizard_room.c


#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", HIW "游戏进度表" NOR);
	set("long", @LONG
这里是一个没有一丝灰尘的小屋，屋里放了一个簿子，是让各位巫师
把所做的改动、目标及完成情况记录下来的本子，上面已经写了厚厚的一
大半了，那可是小雪初晴的巫师们的心血的证明啊！
LONG );

	set("exits", ([
"west" : __DIR__"wizard_room",
 ]));

	set("no_clean_up", 0); 
      setup();
	call_other("/clone/board/lpc_b", "???");
	replace_program(ROOM);
}
