// Room: huikeshi.c
// Created by Zeus 1999.4.8
// Modified by Zeus 1999.4.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "会客室");
        set ("long", @LONG
这里是小字号的会客室，没有总部大字号的前厅的那种气派，
可是这里也非常严肃。抬头可以看到一幅写着小字号的牌匾，中
间放着一张太师椅。有两个温家弟子守在这里。北面就是大院，
向南走就是草地。
LONG);
        set("area","岭南");
	set("valid_startroom", 1);
        set("objects", ([
                "/kungfu/class/wenjia/wenxinlaoxie" : 1,
        ]));

        set("exits", ([
                "south" : __DIR__"caodi",
                "north" : __DIR__"dayuan",
        ]));
        setup();
        replace_program(ROOM);
}
