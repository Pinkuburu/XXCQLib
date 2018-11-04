// Room: jzroad2.c

inherit ROOM;
void create()
{
	set("short", "松树林");
	set("long", @LONG
这是一片松树林。中间一条小路，两边都是黑森森的几丈高的松树。
快出林了，可以看到东北边好高的一座大山，那里应该就是飞鱼塘的后山
了。
LONG );
	set("exits", ([
		"south" : __DIR__"jzroad1",
		"northeast" : __DIR__"jzroad3",
	]));
	set("outdoors", "feiyu");

	setup();
	replace_program(ROOM);
}


