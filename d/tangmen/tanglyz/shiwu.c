//shiwu.c		四川唐门—石屋

inherit ROOM;

void create()
{
	set("short", "石屋");
        set("long",@LONG
这是一间用翠竹搭成的小舍, 一进门, 便闻到一阵浓烈的花香，
房中挂着一幅仕女图, 椅上铺了绣花锦垫, 东边有一扇门, 挂着绣
了一丛牡丹的锦缎门帏. 难道这是谁家姑娘的闺房？
LONG);
        set("exits", ([
                "north" :__DIR__"huayuan",   
           ]));
	set("objects", ([__DIR__"npc/tanglyz" : 1 ]));
        setup();
        replace_program(ROOM);
}