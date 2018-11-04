// Room: xipianting.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "西偏厅");
        set ("long", @LONG
这里的摆设和东偏厅一模一样，也是飞鱼塘两大“老头子”练剑的地
方。东南方的门是通往前厅的，而东北方的门也是通往飞鱼庄内堂的。而
西北方则是女弟子的西武院了。
LONG);
        set("area"," 飞鱼");
        set("valid_startroom", 1);

        set("exits", ([
                "northeast" : __DIR__"neitang",
                "southeast" : __DIR__"qianting",
                "northwest" : __DIR__"xiwuyuan",   
        ]));

        setup();
        replace_program(ROOM);
}
