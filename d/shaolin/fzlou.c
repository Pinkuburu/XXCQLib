// Room: /d/shaolin/fzlou.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "方丈楼");
	set("long", @LONG
这里的地上整整齐齐的排放着数十个黄布蒲团，北首有一个红木讲坛
，讲坛上放着个竹制的木鱼。东西边各放着一对美轮美奂的大花瓶，上插
檀香数枝，香烟缭绕，氤氲芬芳，室内一片祥和之气。看来这里是方丈对
僧众讲经说法的地方。
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"south" : __DIR__"wuchang5",
		"up" : __DIR__"fzlou1",
		"north" : __DIR__"wuchang3",
		"east" : __DIR__"zoulang7",
		"west" : __DIR__"zoulang6",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

