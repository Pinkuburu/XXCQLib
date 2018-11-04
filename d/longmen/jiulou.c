
inherit ROOM;

void create()
{
        set("short", "龙门酒楼");
        set("long", @LONG
为了方便行走的瘾君子，不知是谁在这建了一座酒楼，真是很有眼光。
单从这来往的人群就知道这生意是多么的红火。那些瘾君子多半上去喝两盅
而游客多是买点包子、鸡腿、米酒就赶路去了。楼上是雅座。
LONG );
        set("valid_startroom",1);
        set("exits", ([
                "north" : __DIR__"xijie",
                "up" : __DIR__"jiulou2",
        ]));
        set("objects", ([
                __DIR__"npc/xiaoer2" : 1,
        ]));
//      set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

