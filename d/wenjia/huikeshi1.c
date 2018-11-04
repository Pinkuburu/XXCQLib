// Room: huikeshi1.c
// Created by Zeus 1999.4.16
// Modified by Zeus 1999.4.16
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "会客室");
        set ("long", @LONG
这里“活字号”的会客室。跟其他字号的会客室一样这里的
太师椅上坐的是活字号的第二把手--温约红。他负责接待来这里
的客人。东面是洞口，西面是研究室，而西南方向上是治疗室，
东南方向上是配药房。
LONG);
        set("area","岭南");
	set("valid_startroom", 1);
        set("objects", ([
                "/kungfu/class/wenjia/wenyuehong" : 1,
        ]));

        set("exits", ([
                "east" : __DIR__"dongkou",
                "west" : __DIR__"yanjiushi",
                "northwest" : __DIR__"zhiliaoshi",
                "southwest" : __DIR__"peiyaofang",
        ]));
        setup();
        replace_program(ROOM);
}
