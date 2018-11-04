// Room: /d/shaolin/wuchang2.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
这里是少林寺的练武场。由无数块巨大的花岗岩石板铺就。上千年的
踩踏已使得这些石板如同镜子般平整光滑。练武场中间竖立着不少草靶。
十来个僧人正在练习武艺。西面有一长溜僧房。
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"south" : __DIR__"zoulang3",
		"west" : __DIR__"wuchang",
		"east" : __DIR__"wuchang7",
		"north" : __DIR__"zoulang7",
	]));
	set("objects",([
		"/kungfu/class/shaolin/tieshu" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "shaolin");
	setup();
	replace_program(ROOM);
}

