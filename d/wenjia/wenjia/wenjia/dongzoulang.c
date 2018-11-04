// Room: dongzoulang.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "东走廊");
        set ("long", @LONG
这是东走廊，走廊右边有一个池塘，几条鱼儿摆动着尾巴在水里畅游。
向西边望去，那里传来吆喝声，那是东练武场。西边是那个充满肃杀气氛
的前厅。
LONG);
        set("area","岭南");
        set("outdoors", "wenjia");
        set("valid_startroom", 1);

        set("exits", ([
                "west" : __DIR__"qianting",
                "east" : __DIR__"donglianwuchang",
        ]));

        setup();
        replace_program(ROOM);
}
