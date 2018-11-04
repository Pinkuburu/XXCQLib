// Room: jzroad3.c

inherit ROOM;

void create()
{
        set("short", "树林外");
        set("long", @LONG
树林外，赫然站着一个汉子，在阴森森的林子边上，凭添一股煞气。
东边是登山的路，西边又是一片森林了。
LONG );
        set("exits", ([ 
            "west"   : __DIR__"shulin1",
            "eastup"  : __DIR__"jzroad4",
            "southwest" : __DIR__"jzroad2",
		]));
        set("objects", ([
		     "/d/feiyu/npc/chuwangong" : 1,
        ]));


        setup();
        replace_program(ROOM);
}

