// Room: xiaojing.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "小径");
        set ("long", @LONG
走出练武场，来到了一条小径。离开了那个充满了叫喊声和汗臭味的
地方，来到这个四周种满树木的地方，你顿时觉得精神为之一震，似乎刚
刚练武的疲劳都没有了。前面北方有一个精致的小舍，那是饭堂。南面是
西练武场。西面有一排房子却不知有什么用。
LONG);
        set("area","岭南");
        set("outdoors", "wenjia");
        set("valid_startroom", 1);

        set("exits", ([
                "south" : __DIR__"xilianwuchang",
                "west" : __DIR__"task_da/shulin1",
                "north" : __DIR__"fantang",
        ]));

        setup();
        replace_program(ROOM);
}