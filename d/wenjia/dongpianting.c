// Room: dongpianting.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.3.26
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "东偏厅");
        set ("long", @LONG
这里的摆设与前厅的差不多，只是物品的档次显然低多了
没有前厅中的肃杀气氛。这是接待次级宾客的地方。西南方的
门是通往前厅的而西北方的门自然是通往议事厅的。
LONG);
        set("area","岭南");
        set("exits", ([
                "northwest" : __DIR__"yishiting",
                "southwest" : __DIR__"qianting",
        ]));
        setup();
        replace_program(ROOM);
}
