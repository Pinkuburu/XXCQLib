// Room: fengfan.c
// Created by Zeus 1999.6.5
// Modified by Zeus 1999.6.5
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "风帆");
        set ("long", @LONG
一只小小的风帆，只能载四五人。而这上面的配置非常完善，完全可
以进行长途旅行。一只风帆被风涨得鼓鼓的，船如飞一样航行着。
LONG);
        set("area","桂林");
        set("outdoors", "guilin");

        setup();
        replace_program(ROOM);
}

