// Room: mudi.c
// Created by Atlus 1999.10.9
// Modified by Atlus 1999.10.9
// 

inherit ROOM;

void create ()
{
        set ("short", "墓地");
        set ("long", @LONG
坟丛间，飘飞着元宝纸钱的灰烬，干草被风吹起，象雨丝般飘着，打
着滚，越滚越大的草团在远处传来的隐隐狼嚎中随风起伏。墓园里，有一
个人在扫墓。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"west" : __DIR__"tulu",
		]));

        set("objects", ([
		"/d/feiyu/npc/cangjian": 1,
	    ]));

        set("outdoors", "feiyu");
        setup();
        replace_program(ROOM); 
}

