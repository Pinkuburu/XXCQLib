// Room: qianting.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.4.3
// Modified Long
// 

inherit ROOM;
void create ()
{
        set ("short", "前厅");
        set ("long", @LONG
走进那宏伟的建筑，来到它的前厅。顿时觉得有一种肃杀的
气氛。正前方的墙壁上画着一只张牙舞爪的金龙，金龙上面的牌
匾上写着“温家总堂”。正中间有两张太师椅，两旁整齐的排着
一排凳子。这里是温家接待外人的地方。向北望去有两个通往偏
厅的门。东西两侧分别是两个走廊。
LONG);
        set("area","岭南");
	set("valid_startroom", 1);
        set("objects", ([
                __DIR__"npc/wenjiadizi" : 2,
        ]));

        set("exits", ([
                "south" : __DIR__"square",
                "northeast" : __DIR__"dongpianting",
                "northwest" : __DIR__"xipianting",
                "east" : __DIR__"dongzoulang",
                "west" : __DIR__"xizoulang",
        ]));
        setup();
        replace_program(ROOM);
}
