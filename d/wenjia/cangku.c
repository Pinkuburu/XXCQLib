// Room: cangku.c
// Created by Zeus 1999.4.16
// Modified by Zeus 1999.4.16
// 修改长描述。
// 

inherit ROOM;
void create ()
{
        set ("short", "仓库");
        set ("long", @LONG
这里是活字号收藏新研制的解毒药的地方，这里一般都是不
能给人进来的。
LONG);
        set("area","岭南");
	set("valid_startroom", 1);
        set("exits", ([
                "north" : __DIR__"yanjiushi",
        ]));
        setup();
        replace_program(ROOM);
}
