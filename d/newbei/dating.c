// 山猫ADX by snow 99-12-4

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", WHT"神雪大厅"NOR);
    set("long",
"这里是小雪初晴神雪山的大厅，大厅里摆放这一本厚厚的留言簿"+
HIC"（board）\n"
NOR"用于弟子间交流使用，如果你有什么话要告诉其他人或有什么事要公布，\n"
"而对方又不在线，你可以在这里"+HIC"（post）"NOR+"。\n"
    );
        set("exits", ([
                "west":__DIR__"houting",
                "east":__DIR__"damen",
                "north":__DIR__"beiting",
                "south":__DIR__"nanting",
        ]));
        set("no_fight", 1);
        set("valid_startroom", 1);
	setup();
}
