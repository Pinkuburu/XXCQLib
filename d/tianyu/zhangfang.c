// Room: 帐房
// Date: by godzilla 1999.11.18


inherit ROOM;

void create()
{
        set("short", "帐房");
        set("long", @LONG
这里是天羽门的帐房，每个天羽弟子都到这而向管事领取奖赏，
房子摆设简单，只有一张桌子，桌子上放着一个算盘，一个管事在
不停的打着算盘。
LONG );
        set("exits", ([
               "south" : __DIR__"dating", 
        ]));
        set("objects",([
                __DIR__"npc/guanshi" : 1,
                ]));
        setup();
        replace_program(ROOM);
}

