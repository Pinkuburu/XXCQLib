// Room: yaofang.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.4.3
// Added Find Yao
// 

inherit ROOM;

void init();
int do_zhao(string);

void create ()
{
        set ("short", "药房");
        set ("long", @LONG
一股浓浓的药味弥漫着整个房间。这里排列着几个药柜，一
些基本的接毒药和金创药是可以在这里找到的。
LONG);
        set("area","岭南");
        set("exits", ([
                "west" : __DIR__"bingqifang",
        ]));

        set("objects", ([
                __DIR__"npc/wenjiadizi" : 1,
        ]));

        setup();
}
void init()
{
        add_action("do_zhao", "zhao");
}

int do_zhao(string arg)
{

        object yao;

        if (!arg || (arg != "yao"))
	{
                return notify_fail("你要找什么？\n");	
        }
		
        write("你找到一包金创药。\n");

        yao=new("/d/wenjia/obj/jinchuang");
        yao->move(this_player());

        return 1;
}

