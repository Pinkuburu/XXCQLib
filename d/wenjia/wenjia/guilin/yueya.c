// Room: yueya.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "月牙山");
        set ("long", @LONG
月牙山得名与洞口状如月牙。山西麓的龙隐岩，有不少石刻、诗文
百余件，称为“桂海碑林”。
LONG);
        set("area","桂林");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("exits", ([
                "northeast" : __DIR__"guishulin2",
        ]));
        setup();
        replace_program(ROOM);
}

