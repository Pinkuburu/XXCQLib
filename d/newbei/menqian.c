// 山猫ADX by snow 99-12-4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"神雪山广场"NOR);
	set("long",
"这里是"+HBRED WHT"小雪初晴神雪山"NOR+
"的门前广场，广场的地面全都是铺着一尺\n"
"见方的青石。这里经常围着一群小浑混，由于山中弟子都还不善于在闯，\n"
"荡江湖。这些小浑混经常到山上生事。\n"
    );
        set("exits", ([
                "west":__DIR__"damen",
                "east":__DIR__"shanyao",
        ]));
        set("no_fight", 1);
        set("valid_startroom", 1);
	setup();
        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if( (dir=="west")
    &&(me->query("newbei")==1)
		&& !wizardp(me) )
	return notify_fail(HIC"你已经不需要进入山中学习了！\n"NOR);
	return ::valid_leave(me, dir);
}
