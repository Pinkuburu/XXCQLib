// Room: /d/wizard/wizard_room.c

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", HIW "会议室" NOR);
	set("long", @LONG
这是一间很大的会议室，乳白色的圆桌，中间种着珍贵的花草，平时
巫师们就在这里举行会议，讨论各种决定各种问题。也不时有玩家被邀请
来提出宝贵的意见。
LONG );

	set("exits", ([
  	"south"  : __DIR__"wizard_room",	
 ]));

	set("no_clean_up", 0); 
        set("recordable_room",1);
      setup();

	replace_program(ROOM);
}
