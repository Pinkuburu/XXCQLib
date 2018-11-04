// Room: shangu2.c
//Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "山谷");
        set ("long", @LONG
这里的地势比较平坦，你觉得似乎步子快多了，向东望去，只见一座
高耸入云的山峰挡住了你的视线，在山谷里还有不少的小动物四处奔走。
山谷向北延伸着，东南方却可看见山间的一些小屋。
LONG);
        set("area","飞鱼");
        set("outdoors", "feiyu");

       

        set("exits", ([
                "northup" : __DIR__"shangu1",
                "southeast" : __DIR__"shanjianxiaowu",
        ]));
        setup();
        replace_program(ROOM);
}
