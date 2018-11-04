// Room: zhidushi.c
// Created by Zeus 1999.4.8
// Modified by Zeus 1999.4.10
// 修改长描述。
// 

inherit ROOM;
void create ()
{
        set ("short", "制毒室");
        set ("long", @LONG
这里小字号的制毒室。在实验室里实验好的药品就会拿到这
里来批量制造。这里的制造工具一应具全。东面是大院，向下走
就是材料室。
LONG);
        set("area","岭南");
	set("valid_startroom", 1);
        set("exits", ([
                "east" : __DIR__"dayuan",
                "down" : __DIR__"cailiaofang",
        ]));
        setup();
        replace_program(ROOM);
}
