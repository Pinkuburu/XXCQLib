//changan city

inherit ROOM;

void create ()
{
        set ("short", "石板路");
        set ("long", @LONG
这是一条石板路，由于每日都有无数的人在这里走过，石板已被磨的
非常的光亮。路往西北面应该通向九曲廊，而往东面下了台阶就是宽敞的
练武场了。站在这里可以看到练武场上的浣花弟子练得热火朝天的情景。�
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"north" : __DIR__"jqlang_1",
		"east" : __DIR__"moneyroom",
		"southdown" : __DIR__"wuchang1",
	]));

        set("outdoors", "xiao");
        setup();
	replace_program(ROOM);
}