// Room: jzroad1.c

inherit ROOM;
void create()
{
	set("short", "松树林");
	set("long", @LONG
这是一片松树林。中间一条小路，两边都是黑森森的几丈高的松树。
树上结着不少松果，间或有野兔游悠游而过。再向南就是西武场。
LONG );
	set("exits", ([
		"south" : __DIR__"wroad",
		"north"      : __DIR__"jzroad2",
	]));
//     set("objects", ([
//         "/d/feiyu/npc/yetu": 2,
//     ]));
	set("outdoors", "feiyu");

	setup();
	replace_program(ROOM);
}

