
inherit ROOM;
void create()
{
        set("short","东方大厅");
        set("long",@LONG
 你已经来到了权力帮的中心地带。
LONG );
        set("valid_startroom",1);
        set("class","权力帮");
        set("exits",([
                "west" : __DIR__"zoulang2",
                 "enter" : __DIR__"biandian",
        ]));
        set("objects",([
        ]));
//        set("no_clean_up"， 0);
        set("objects",([
          __DIR__"npc/futianyi" : 1,
    ]));
        setup();
        replace_program(ROOM);
}

