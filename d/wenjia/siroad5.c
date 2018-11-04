// Room: siroad5.c
// Created by Zeus 1999.4.16
// Modified by Zeus 1999.4.17
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "山路");
        set ("long", @LONG
这里是到“死字号”的山路，路旁种的都是一些奇异花草。
说不定这些花草是有毒的？还是快些离开这里吧。向南上去是
山路，东北方向走也是山路。
LONG);
        set("area","岭南");
        set("outdoors", "wenjia");

        set("exits", ([
                "northeast" : __DIR__"siroad4",
                "southup" : __DIR__"siroad6",
        ]));
        setup();
        replace_program(ROOM);
}

