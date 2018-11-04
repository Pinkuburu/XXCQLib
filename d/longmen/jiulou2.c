// Room: /city/zuixianlou2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
        set("short", "酒楼二层");
        set("long", @LONG
这里是雅座，文人学士经常在这里吟诗作画，富商土豪也在这里边吃喝
边作交易。这里也是镇里举办喜宴的最佳场所。你站在楼上眺望，只觉得心
旷神怡。墙上挂着价格牌子(paizi)。
LONG );
        set("valid_startroom",1);
        set("item_desc", ([
                "paizi" : "本店出售烤鸭及上等花雕酒。\n",
        ]));
        set("objects", ([
                __DIR__"npc/baobao" : 1,
        ]));
        set("exits", ([
                "down" : __DIR__"jiulou",
//              "east": __DIR__"zxlpath",
        ]));
//      set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

