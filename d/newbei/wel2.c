// 山猫ADX by snow 99-12-4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",WHT"欢迎光临小雪初晴"NOR);
	set("long",
"如果你肚子饿了可以用"+HIC"(eat xxxx)"NOR+"指令吃东西，渴了还可以用"+HIC"(drink xxxx)"NOR+"\n"
"指令喝水，地上有东西你可以用"+HIC"(get xxxx、get all)"NOR+"捡起来，当然，你最好还是去\n"
"买"+HIC"(buy xxxx)"NOR+"去买些你需要的东西，你也可以把你不用的东西卖掉，"
HIC"(sell)"NOR+"，如果\n"
"你累了，可以睡上一觉"+HIC"(sleep)"NOR+"，当然你必需找到能睡觉的地方。\n"
);
        
        set("exits", ([
                "south":__DIR__"wel3",
        ]));
        set("objects",([
                __DIR__"npc/jieyinshi2":1,
                ]));
	set("no_fight", 1);
        
	setup();
        replace_program(ROOM);
}
