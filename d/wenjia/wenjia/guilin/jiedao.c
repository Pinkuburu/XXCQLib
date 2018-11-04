// Room: jiedao.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "街道");
        set ("long", @LONG
这里是桂林镇上的街道。由于这里是壮族的聚集地，所以到处都可以
看见穿着壮族服饰的人走来走去。西面是一间客栈。向北延伸就是一片桂
树林。
LONG);
        set("area","桂林");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("objects", ([
                __DIR__"npc/zzoldwoman" : 1,
        ]));

        set("exits", ([
                "north" : __DIR__"guishulin4",
                "south" : __DIR__"zhongxin",
                "west" : __DIR__"kezhan",
        ]));
        setup();
        replace_program(ROOM);
}

