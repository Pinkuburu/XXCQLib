//changan city

inherit ROOM;

void create ()
{
        set ("short", "大栅栏东街");
        set ("long", @LONG
这是大栅栏东街的尽头，往东已经没有路了，但即使比较偏僻，仍有许多人到
这里，因为这里的路北是京城唯一的一家药铺，无论有什么病人们总要到这里来抓
药，路南则是一家小酒馆，劳累了一天的人们经常光顾这里，不过这里是见不到那
些达官贵人和纨绔子弟的身影的。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"west" : __DIR__"shalan-e1",
		"north" : __DIR__"yaopu",
		"south" : __DIR__"yideju",
        ]));

        set("outdoors", "beijing");
        setup();
	replace_program(ROOM);
}