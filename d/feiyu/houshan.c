// Room: houshan.c


inherit ROOM;

void create()
{
        set("short", "后山");
        set("long", @LONG
这里是后山的一个小平台。定睛一看，此处已经是云雾缥缈。不远的
地方好象有个小湖。北边的山路延伸到雾里，已经看不清了。
LONG );
        set("exits", ([ 
            "southdown" : __DIR__"jzroad3",
            "northwest"  : __DIR__"xiaohu",
            "northup"  : __DIR__"disanfeng",
		]));
        set("outdoors", "feiyu");

		setup();
        replace_program(ROOM);
}

