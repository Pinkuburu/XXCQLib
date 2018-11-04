// Room: qianting.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "前厅");
        set ("long", @LONG
这里是飞鱼塘总部的前厅。走到这里顿时觉得有一种肃杀的气氛。左
右两边的墙壁上各画着一副“鱼跃龙门”，正前面的牌匾上写着“飞鱼总
堂”。正中间有一张虎皮椅，两旁整齐的站着一排飞鱼塘的弟子。这里是
飞鱼塘处理塘中大事的地方。向北望去有两个通往偏厅的门。东西两侧分
别是练武场。
LONG);
        set("area","飞鱼");
        set("valid_startroom", 1);

        set("exits", ([
                "south" : __DIR__"lysquare",
                "northeast" : __DIR__"dongpianting",
                "northwest" : __DIR__"xipianting",
                "east" : __DIR__"dongwuchang",
                "west" : __DIR__"xiwuchang",
        ]));

        setup();
        replace_program(ROOM);
}
