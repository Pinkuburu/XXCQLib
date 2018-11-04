// Room: dongpianting.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "东偏厅");
        set ("long", @LONG
这里的摆设与前厅的差不多，只是物品的档次显然低多了没有前厅中
的肃杀气氛。这是接待次级宾客的地方。西南方的门是通往前厅的而西北
方的门自然是通往议事厅的。
LONG);
        set("area","岭南");
        set("valid_startroom", 1);

        set("exits", ([
                "northwest" : __DIR__"yishiting",
                "southwest" : __DIR__"qianting",
        ]));

        setup();
        replace_program(ROOM);
}
