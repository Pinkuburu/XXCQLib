// Room: guanjiafang.c 管家房
// Created by Zeus 1999.5.28
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "管家房");
        set ("long", @LONG
房间里放着一张书桌，旁边坐着一个老人。桌子后面的书柜里放着的
都是卷宗，桌子上堆满了卷宗，当然少不了有文房四宝，老人的手不停在
写着东西。
LONG);
        set("area","岭南");
        set("valid_startroom", 1);

        set("exits", ([
                "north" : __DIR__"donglianwuchang",
        ]));
        set("objects", ([
                 __DIR__"npc/wengu": 1,
        ]));

        setup();
        replace_program(ROOM);
}
