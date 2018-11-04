// Room: yishiting.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.3.26
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "议事厅");
        set ("long", @LONG
这里摆着一圈椅子，很显然，那是让在这里议事的人坐的吧
东南方和西南方的两个门是很显然是从前厅来这里的两个偏厅。
LONG);
        set("area","岭南");
	set("valid_startroom", 1);
        set("objects", ([
                "/kungfu/class/wenjia/wenxinlaoxie" : 1,
                "/kungfu/class/wenjia/wennuansan" : 1,
                "/kungfu/class/wenjia/wenyuehong" : 1,
                "/kungfu/class/wenjia/wenliangyu" : 1,
                "/kungfu/class/wenjia/wensijuan" : 1,
                "/kungfu/class/wenjia/wenlazi" : 1,
                "/kungfu/class/wenjia/wendi" : 1,
                "/kungfu/class/wenjia/wenshagong" : 1,
        ]));

        set("exits", ([
                "southwest" : __DIR__"xipianting",
                "southeast" : __DIR__"dongpianting",
        ]));
        setup();
        replace_program(ROOM);
}
