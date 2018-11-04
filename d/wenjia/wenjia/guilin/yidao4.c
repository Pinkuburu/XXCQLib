// Room: yidao4.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "驿道");
        set ("long", @LONG
朝廷传送公文的驿道，不时有马骑从身边经过。驿道上尘土飞扬，而
两边种植了一些矮矮的小树，整个景色显得有些苍凉。向西北方走就要进
入华阳镇了。而东南方还是长长的驿道。
LONG);
        set("area","成都");
        set("outdoors", "chengdu");
	set("valid_startroom", 1);

        set("exits", ([
                "southeast" : __DIR__"yidao3",
                "northwest" : "/d/chengdu/hyroad4",
        ]));
        setup();
        replace_program(ROOM);
}

