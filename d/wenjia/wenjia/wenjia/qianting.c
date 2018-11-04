// Room: qianting.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.7.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "前厅");
        set ("long", @LONG
走进那宏伟的建筑，来到它的前厅。顿时觉得有一种肃杀的气氛。正
前方的墙壁上画着一只张牙舞爪的金龙，金龙上面的牌匾上写着“温家总
堂”。正中间有两张太师椅，两旁整齐的排着一排凳子。这里是温家接待
外人的地方。向北望去有两个通往偏厅的门。东西两侧分别是两个走廊。
LONG);
        set("area","岭南");
        set("valid_startroom", 1);

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
