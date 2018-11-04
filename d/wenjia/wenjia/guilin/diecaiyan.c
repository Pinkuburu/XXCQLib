// Room: diecaiyan.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "叠彩岩");
        set ("long", @LONG
叠彩岩的由来是因为岩层水平如叠彩锦。半山有一特异风洞，南北对
穿，仅能过人，四季都有清风，故名风洞。山上有叠彩亭、仰止堂等唐代
的著名石刻。
LONG);
        set("area","桂林");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("exits", ([
                "south" : __DIR__"guishulin",
        ]));
        setup();
        replace_program(ROOM);
}

