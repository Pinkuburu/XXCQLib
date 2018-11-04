// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "七曲廊");
	set("long", @LONG
七曲廊曲曲折折，如果不是权力帮的缘故，这里曾经是浣花弟子最喜
欢休憩的地方，但现在，除了匆匆的脚步，你再也听不到欢声笑语了。从
北面走出长廊是落花别院，振眉阁就在落花别院内。
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"east" : __DIR__"qqlang_1",
		"southwest" : __DIR__"qqlang_3",
		"north" : __DIR__"luohua",
	]));

        set("objects", ([
	]));

	setup();
	replace_program(ROOM);
}