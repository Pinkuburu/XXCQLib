// Room: donglianwuchang.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.6.10
// 
// 

inherit ROOM;

void init();
int do_da(string);

void create ()
{
        set ("short", "东练武场");
        set ("long", @LONG
这是一个宽敞的练武广场，广场周围放着一些兵器架，兵器架上面有
着各式兵器。至于北面是一个小房子，那时个兵器房。西边是学堂。这里
有一个假人摇摇晃晃的挂在木架上，你很想拿把沙子丢(diu)它。
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
                "south" : __DIR__"guanjiafang",
        ]));

        setup();
}

void init()
{
        add_action("do_da", "diu");
}

int do_da(string arg)
{
        object me;
        int jingli_cost;
        int qi_cost;

        me = this_player();

        if ( !arg || ( arg != "jiaren" ) )
                return notify_fail("你想干什么？\n");

        jingli_cost = (-1) * random(20);
        qi_cost = (-1) * random(20);

        me->add("jingli", jingli_cost);
        me->add("qi", qi_cost);

        if ( me->query("jingli") <= (- jingli_cost) || me->query("qi") <= (-qi_cost) )
                return notify_fail("你太疲劳了，没有精力练功了。\n");

        message_vision("$N摆好架势，抓起一把沙子向假人丢去。\n", me);

        if ( me->query_skill("lphand", 1) < 10 )  
        {
                message_vision("结果$N丢的沙子一颗也没丢中假人。\n", me);
   		
        } else if ( me->query_skill("lphand", 1) < 20 )
        {
                message_vision("$N丢的沙子有一半丢中假人。\n", me);
        } else 
        {
                message_vision("Bingo!$N丢的沙子全中假人。\n", me);
        }
 
        if ( me->query_skill("lphand", 1) < 30)
        {
                me->improve_skill("unarmed", me->query("int"));
                me->set_temp("hitted",1);
        }
        if ( !me->query_temp("hitted") )
        { 
                write("你觉得现在丢沙子对自己没什么作用了！\n");
        }
        return 1;
}