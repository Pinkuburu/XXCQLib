// Room: bingfang.c
// Created by Zeus 1999.4.16
// Modified by Zeus 1999.4.16
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "病房");
        set ("long", @LONG
这里活字号的病房，温家弟子中了毒后在南面的治疗室解毒，
然后在休息。这里周围有几张床铺，上面躺着几个病人。
LONG);
        set("area","岭南");
	set("valid_startroom", 1);
        set("exits", ([
                "south" : __DIR__"zhiliaoshi",
        ]));
        setup();
        replace_program(ROOM);
}
