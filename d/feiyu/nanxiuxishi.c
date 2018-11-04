// Room: nanxiuxishi.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "男休息室");
        set ("long", @LONG
这间房间里弥漫着一些古怪的气味，你顿时觉得不太自在。你看看四
周，发现这里排着几张床铺，床铺非常舒适。床上却是乱七八糟，还有几
个人在呼呼大睡。房间尽头有一张桌子，桌子上燃着一种香，还有一大堆
刚换的衣服胡乱丢在桌上。
LONG);
        set("area","岭南");
        set("valid_startroom", 1);
        set("sleep_room", "1");
        set("no_fight", "1");

        set("exits", ([
                "south" : __DIR__"wxiaojing",
        ]));

        setup();
        replace_program(ROOM);
}
