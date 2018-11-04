// Room: yixiantiannei2.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "一线天内");
        set ("long", @LONG
“一线天”果然名不虚传，从这里向上看两旁高耸的峭壁间只露出一
条白线，两旁的峭壁上长满了奇怪的植物，在黑夜里张牙舞爪。隐约可以
看见南面的山峰。四周一个人也没有，一阵风吹过，四周发出了奇怪的声
音，你感到背上有些寒意。
LONG);
        set("area","飞鱼");
        set("outdoors", "feiyu");

        
        set("exits", ([
                "northup" : __DIR__"yixiantiannei",
                "west" : __DIR__"diliufeng",
        ]));
        setup();
        replace_program(ROOM);
}
