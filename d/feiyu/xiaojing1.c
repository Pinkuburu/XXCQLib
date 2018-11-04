// Room: xiaojing1.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 

inherit ROOM;

void create ()
{
        set ("short", "小径");
        set ("long", @LONG
这是一条青石铺成的小径，四周都可以听见小鸟的叫声。从这里再向
北走就到飞鱼塘的东练武场了，而向南是一大片树林，隐约看得见树林中
有些移动的影子。
LONG);
	set("valid_startroom", 1);
       set("outdoors", "feiyu");
       set("exits", 
        ([
		"north" : __DIR__"dongwuchang",
		"south" : __DIR__"shulin",
       ]));

                setup();
        replace_program(ROOM); 
}

