// Room: shanjing1。c

inherit ROOM;
void create ()
{
        set ("short", "山间小径");
        set ("long", @LONG
这里是一条弯弯曲曲的山间小径一直向西南方延伸着。小径两边都是
奇怪的岩石，周围没有一个人影。你似乎听到了水流的咆哮声，看来离龙
门瀑布不远了。
LONG);
        set("area","龙门");
        set("outdoors","龙门");

	set("valid_startroom",1);
        set("exits", ([
                "west" : __DIR__"tanbian",
                "south" : __DIR__"hsxj1",
        ]));
        setup();
        replace_program(ROOM);
}