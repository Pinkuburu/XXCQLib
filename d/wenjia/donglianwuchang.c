// Room: donglianwuchang.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.4.10
// 修改武功种类。
// 

inherit ROOM;

void init();
int do_da(string);

void create ()
{
        set ("short", "东练武场");
        set ("long", @LONG
这是一个宽敞的练武广场，广场周围放着一些兵器架，兵器
架上面有着各式兵器。至于北面是一个小房子，那时个兵器房。
西边是学堂。这里有一个木人，你很想打打(da)它。
LONG);
        set("area","岭南");
	set("valid_startroom", 1);
        set("outdoors", "wenjia");

        set("objects", ([
                __DIR__"npc/wenjiadizi" : 2,
        ]));

        set("exits", ([
                "west" : __DIR__"dongzoulang",
                "east" : __DIR__"xuetang",
                "north" : __DIR__"bingqifang",
        ]));
        setup();
}

void init()
{
        add_action("do_da", "da");
}

int do_da(string arg)
{
        object me;
        int jingli_cost;
        int qi_cost;

        me = this_player();

        if ( !arg || ( arg != "muren" ) )
                return notify_fail("你想干什么？\n");

        jingli_cost = (-1) * random(20);
        qi_cost = (-1) * random(20);

        me->add("jingli", jingli_cost);
        me->add("qi", qi_cost);

        message_vision("$N摆好架势，向木人打去。\n", me);

        if ( (int)me->query_skill("atrike", 1) < 10 )  
        {
                message_vision("结果$N觉得手打得十分疼。\n", me);
   		
        } else if ( (int)me->query_skill("strike", 1) < 20 )
        {
                message_vision("$N觉得手不怎么痛了。\n", me);
        } else 
        {
                message_vision("$N觉得就像打小人一样，容易！\n", me);
        }
 
        if ( (int)me->query_skill("strike", 1) < 30)
        {
                me->improve_skill("strike", me->query("int"));
                me->set_temp("hitted",1);
        }
        if ( !me->query_temp("hitted") )
        { 
                write("你觉得打木人对自己没什么作用了！\n");
        }
        return 1;
}