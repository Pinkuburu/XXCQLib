//changan city

inherit ROOM;

void create ()
{
        set ("short", "大栅栏西街");
        set ("long", @LONG
这是这条繁华闹市相对比较安静的一段，这是因为除了到大光明栈住店的人以
外其他的人是很少走到这里的。这里路南就是京城最便宜的客店“大光明栈”，路
北则是闻名于京城的字画店“愁石斋”。向西已经没有路了，如果您不是来住店或
是买字画，那么您只好向东边的来路走回去了。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
                "north" : __DIR__"choushizhai",
		"east" : __DIR__"shalan-w1",
                "south" : __DIR__"kedian",
        ]));

        set("objects", 
        ([
        ]));


        set("outdoors", "beijing");
        setup();
	replace_program(ROOM);
}