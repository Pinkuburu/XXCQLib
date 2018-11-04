// Room: nanxiuxishi.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.4.3
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "男休息室");
        set ("long", @LONG
这间房间里氤氲着一些红色的雾气，顿时觉得精神昏昏沉沉的。你
用快要闭上的眼睛看看四周，发现这里排着几张床铺，床铺非常舒适。
床上躺着几个人，他们都在呼呼大睡。房间尽头有一张桌子，桌子上
燃着一种香，据别人说那是温家专门研制用来催眠的香。
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
