// Room: jiangdi.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "芦笛岩");
        set ("long", @LONG
芦笛岩是一座雄奇瑰丽的石灰岩溶洞。洞内有大量钟乳石，绚丽多彩，
精巧神奇。是游客必来的地方。
LONG);
        set("area","桂林");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("exits", ([
                "southeast" : __DIR__"guishulin4",
        ]));
        setup();
        replace_program(ROOM);
}

