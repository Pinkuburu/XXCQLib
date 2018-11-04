// huangshanjie4.c

#include <room.h>

inherit ROOM;

void create()
{	
	set("short", "黄衫街");
	set("long", @LONG
这段街出奇的冷清，只有阵阵操练声从左右传来，原来街的两边是汴
梁城驻城军营的所在地，因为城军向来张扬跋扈，所以没有普通百姓敢在
这里停留，你也快点走开吧。
LONG);	
	set("valid_startroom",1);

	set("exits", ([
		"north" : __DIR__"huangshanjie3",
		"south" : __DIR__"huangshanjie5",
		"west" : __DIR__"bingying1",
		"east" : __DIR__"bingying2",
	]));

	set("outdoors", "bianliang");
	set("area", "汴梁");

	setup();

	replace_program(ROOM);
}