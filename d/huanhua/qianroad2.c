//changan city

inherit ROOM;

void create ()
{
        set ("short", "花坛");
        set ("long", @LONG
转过影壁，是一个大大的花坛，花坛中的花有半人高，牡丹、玫瑰、
月季各色各样花草密布其中，煞是美丽。花坛的西边是一座红色两层高的
阁楼，走左右的曲廊则可以到剑庐的其他地方。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"east" : __DIR__"qianroad1",
		"south" : __DIR__"southlang",
		"west" : __DIR__"tingyudoor",
		"north" : __DIR__"northlang",
	]));

        set("objects", ([
                 "/kungfu/class/huanhua/baiyun": 1,
	]));

        set("outdoors", "xiao");
        setup();
	replace_program(ROOM);
}