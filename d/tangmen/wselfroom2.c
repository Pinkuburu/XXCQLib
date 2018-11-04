//wselfroom2.c  by winder

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "卧室");
	set("long", @LONG
这是一间温暖的卧室。这里是唐门XXXX居住的地方，房间宽敞明亮，
墙壁粉刷的雪白，窗边摆放着一张宽大的软床，床头有一张被擦拭的一
尘不染的红木方桌，门口垂手站立着一名侍从，随时准备听候主人的吩
咐。
LONG);	
	set("valid_startroom",1);
	set("no_steal", "1");
	set("no_fight", "1");
	set("sleep_room",1);
	set("exits", ([	"south" : __DIR__"wzlang2",]));
	setup();
	replace_program(ROOM);
}