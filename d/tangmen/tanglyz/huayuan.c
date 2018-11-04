//huayuan.c		四川唐门—花园

inherit ROOM;

void create()
{
	set("short", "花园");
	set("long", @LONG
从漆黑的地道中出来, 你发现自己竟是置身于一个极精致的小花
园中, 红梅绿竹, 青松翠柏, 布置得颇具匠心, 往南去是一间青石小
屋。
LONG);
	set("exits", ([
			"east" : __DIR__"andao2",
			"south" : __DIR__"shiwu",
	]));
	set("area", "蜀中");
	setup();
	replace_program(ROOM);
}