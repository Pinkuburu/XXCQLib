//changan city

inherit ROOM;

void create ()
{
        set ("short", "大栅栏东街");
        set ("long", @LONG
这段街两侧坐落着两家对百姓来讲极为重要的店铺，其中路南一家是北京最大
的杂货铺，几乎所有的生活用品都可以在这里买到，路北则是京城两家钱庄之一，
虽然在这里不能存很多钱，但由于这里不收手续费，所以普通人家的钱都是存到这
里的。向东似乎有家小酒铺，向西则是大栅栏街口，从那里可以通向城南的各个地
方。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
		"east" : __DIR__"shalan-e2",
		"west" : __DIR__"shalan",
		"north" : __DIR__"qianzhuang",
		"south" : __DIR__"zahuopu",
        ]));

        set("objects", 
        ([
        ]));


        set("outdoors", "beijing");
        setup();
	replace_program(ROOM);
}