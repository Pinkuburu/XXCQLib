// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "北厢回廊");
	set("long", @LONG
整个的剑庐是连绵不断的回廊连接的，现在所在的北厢回廊的左、右
分别是花坛和北厢院，而沿着回廊向西则通向黄河小轩、七回廊等地方，
不时有浣花弟子走过这里。
LONG
	);

	set("valid_startroom", 1);

	set("exits", ([
		"south" : __DIR__"qianroad2",
		"north" : __DIR__"northyuan",
		"west" : __DIR__"northlang_2",
	]));

        set("objects", ([
	]));

	setup();
	replace_program(ROOM);
}