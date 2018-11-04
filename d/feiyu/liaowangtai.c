// Room: liaowangtai.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "了望台");
        set ("long", @LONG
这里是“人止关”旁的一个了望台，大概是为了观察四周环境用的吧
，这里的雾比山间少多了，所以可以清晰地看见北面的一个大广场，那里
应该就是飞鱼山庄的大广场吧！你深呼吸了几下，感到空气十分清新，使
人心旷神怡。
LONG);
        set("area","飞鱼");
        set("outdoors", "feiyu");

        

        set("exits", ([
                "south" : __DIR__"renzhiguan",
        ]));
        setup();
        replace_program(ROOM);
}
