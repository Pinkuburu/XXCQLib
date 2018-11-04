// Room: xiangbi.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "象鼻山");
        set ("long", @LONG
象鼻山位于桃花江与漓江的汇流处。山型如大象伸鼻吸水，形象逼真，
神态自然。鼻与脚之间形成圆洞，名叫水月洞。山顶有普贤塔。象鼻山已
称为了桂林山水的代表。
LONG);
        set("area","桂林");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("exits", ([
                "northwest" : __DIR__"guishulin3",
        ]));
        setup();
        replace_program(ROOM);
}

