// Room: /city/chouduanhang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "观鱼阁");
	set("long", @LONG
观鱼阁的一层没有什么特别的地方，一张书案，几把木椅，这里是任
何浣花弟子都可以休息的地方，而楼上一般来讲只要大小姐在，别人就不
进去了。但说到在观鱼阁观鱼，却又是非上二层不可的。
LONG);

	set("valid_startroom", 1);

	set("exits", ([
		"north" : __DIR__"jqlang_2",
		"up" : __DIR__"guanyu_2",
	]));

        set("objects", ([
                 __DIR__"npc/guiyuan": 1,
	]));

	setup();
	replace_program(ROOM);
}