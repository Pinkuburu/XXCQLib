// Room: dongpianting.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "东偏厅");
        set ("long", @LONG
这里的摆设十分朴素，这里是飞鱼塘两大“老头子”练剑的地方。西
南方的门是通往前厅的而西北方的门是通往飞鱼庄内堂的。而东北方则是
男弟子的东武院了。
LONG);
        set("area"," 飞鱼");
        set("valid_startroom", 1);

        set("exits", ([
                "northwest" : __DIR__"neitang",
                "southwest" : __DIR__"qianting",
                "northeast" : __DIR__"dongwuyuan",   
        ]));

        setup();
        replace_program(ROOM);
}
