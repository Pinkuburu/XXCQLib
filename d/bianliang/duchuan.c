// Room: duchuan
// Date: 

inherit ROOM;

void create()
{
        set("short", "渡船");
        set("long", @LONG
一叶龙门小舟，最多也就能载几个人。一名五十多岁的艄公
手持长竹篙，正在船尾用力的撑着船。
LONG );
        set("no_clean_up", 0);
        set("outdoors", "汴梁");
        setup();
        replace_program(ROOM);
}

