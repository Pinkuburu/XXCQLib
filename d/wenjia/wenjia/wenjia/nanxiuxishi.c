// Room: nanxiuxishi.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "男休息室");
        set ("long", @LONG
这间房间里氤氲着一些红色的雾气，顿时觉得精神昏昏沉沉的。你用
快要闭上的眼睛看看四周，发现这里排着几张床铺，床铺非常舒适。床上
躺着几个人，他们都在呼呼大睡。房间尽头有一张桌子，桌子上燃着一种
香，据别人说那是温家
专门研制用来催眠的香。
LONG);
        set("area","岭南");
        set("valid_startroom", 1);
        set("sleep_room", "1");
        set("no_fight", "1");

        set("exits", ([
                "east" : __DIR__"fantang",
        ]));

        setup();
        replace_program(ROOM);
}
