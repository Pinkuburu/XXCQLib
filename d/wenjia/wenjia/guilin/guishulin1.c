// Room: guishulin.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "桂树林");
        set ("long", @LONG
茂密的桂树林，这里种植着一片茂密的桂树林，而这里被称为桂林的
原因就是因为桂林周围有非常多的桂树林。这里是去七星岩的必经之路。
LONG);
        set("area","桂林");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("exits", ([
                "northwest" : __DIR__"jiangdi",
                "south" : __DIR__"guishulin2",
        ]));
        setup();
        replace_program(ROOM);
}

