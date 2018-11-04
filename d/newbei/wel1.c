// 山猫ADX by snow 99-12-4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",WHT"欢迎光临小雪初晴"NOR);
	set("long", 
"你混混沌沌的来到了一个陌生的世界，你想看看你在哪里"+HIC"(l, look),\n"NOR
"你想知道这个世界里都有谁"+HIC"(who)"NOR+",或许你要四处走走，"+
HIC"(w,s,n,e,nw,ne,\n"
"sw,se,d,u,sd,nd,wd,ed,wu,nu,eu,su)"NOR+"，不过你得先看看都有那些明显出口。\n"
 );
        set("exits", ([
                "east":__DIR__"wel2",
                "south":__DIR__"welx",
                
        ]));
        set("objects",([
                __DIR__"npc/jieyinshi1":1,
                ]));
	set("no_fight", 1);
	setup();
	replace_program(ROOM);
}
