//changan city

inherit ROOM;

void create ()
{
        set ("short", "较武场");
        set ("long", @LONG
这是一个极其宽敞的较武场，是剑庐弟子比武的地方，浣花四代弟子
、十年会之一的悲愤在这里主持比武并传授浣花弟子武功。在较武场左右
各有一块练武场，有一些辅助设备帮助练武。
LONG);
	set("valid_startroom", 1);

        set("objects", ([
                 "/kungfu/class/huanhua/beifen": 1,]));

        set("exits", 
        ([
		"northup" : __DIR__"wuroad2",
		"east" : __DIR__"wuchang2",
		"west" : __DIR__"wuchang3",
	]));

        set("outdoors", "xiao");
        setup();
	replace_program(ROOM);
}