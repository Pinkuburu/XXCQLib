//changan city

inherit ROOM;

void create ()
{
        set ("short", "京城广场");
        set ("long", @LONG
这是京城最大的广场，也是连接京城两条重要大道的街口，无数的人
从这里走过，但因为总有巡捕、官差在这里巡逻，所以很少有人在这里停
留。这里往北是黄衫街，贯穿东西是黄裤大道，往南就快到了南门了。
LONG);
	set("valid_startroom", 1);

        set("exits", 
        ([
                "west" : __DIR__"huangkudajie5",
		"east" : __DIR__"huangkudajie6",
		"north" : __DIR__"huangshanjie5",
		"south" : __DIR__"nandajie2",
        ]));

	set("objects", ([
             __DIR__"npc/long" : 1,
               __DIR__"npc/dog" : 3,
	]));

	set("area", "汴梁");

        set("outdoors", "bianliang");
        setup();
	replace_program(ROOM);
}
