// Room: /d/playertown/huayuan1.c 花园
// Build 1999.12.10 bmw

inherit ROOM;

void create()
{
        set("short", "花园");
        set("long", @LONG
你走在一条青砖小道上，两边整整齐齐地排着两排杨柳，湖上总
有几艘渔船正在打渔，渔夫们欢快地唱着歌，拖起一网活蹦乱跳的鱼
儿。湖畔边上是一片片翠绿的草坪，上面几对夫妇正相依在那，低头
吟语着，偶尔还传来一阵涩笑。
LONG );
        set("outdoors", "playertown");
//      set("no_clean_up", 0);
        set("exits", ([
                "north" : __DIR__"huayuan2",
                "southwest" : __DIR__"road9",
        ]));
        setup();
        replace_program(ROOM);
}
