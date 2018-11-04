// caodi.c 草地


inherit ROOM;

void create()
{
        set("short", "草地");
        set("long", @LONG
这里是一片草地，草很绿，很浅，显然由于经常有人修剪而保养的很
好。草间散布着一些奇花，微风吹过，芬芳扑鼻。你听到时而有“嗡嗡嗡
”的声音，看见有一些个头奇大的白色的蜜蜂在草地上飞舞盘旋。
LONG
        );
        set("valid_startroom",1);
        set("outdoors", "wenzhai");
        set("exits", ([
                "out" : __DIR__"damen",
                "east"  : __DIR__"chanting",
                "south" : __DIR__"dating",
        ]));

        set("objects", ([
                __DIR__"npc/mifeng" : random(5),
        ]));

        setup();
        replace_program(ROOM);
}
