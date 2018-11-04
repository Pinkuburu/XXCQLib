// Room: duqiu.c
// Created by Zeus 1999.6.4
// Modified by Zeus 1999.6.4
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "独秀峰");
        set ("long", @LONG
独秀峰在镇中心，由于孤峰突兀，如插云霄，有“南天一柱”之称。
正面视之，巍峨端庄；侧面望去，却挺拔俊秀。有“紫袍金带”、“介然
独立”等著名石刻。从西麓上山，有三百零六级石阶，可直达峰顶。
LONG);
        set("area","桂林");
        set("outdoors", "guilin");
	set("valid_startroom", 1);

        set("exits", ([
                "west" : __DIR__"zhongxin",
        ]));
        setup();
        replace_program(ROOM);
}

