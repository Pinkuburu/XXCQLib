// Room: liangongfang.c
// Created by Zeus 1999.4.16
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "练功房");
        set ("long", @LONG
这里是死字号弟子们的练功房。有几个弟子在那里打坐，而旁边有几
个床铺可以在上面睡觉。东面的门是通往会客室的，如果要练习功夫或切
磋武艺的话请到南面的武场。
LONG);
        set("area","岭南");
        set("valid_startroom", 1);
        set("sleep_room", "1");
        set("no_fight", "1");

        set("exits", ([
                "east" : __DIR__"huikeshi2",
                "south" : __DIR__"wuchang",
        ]));

        setup();
        replace_program(ROOM);
}
