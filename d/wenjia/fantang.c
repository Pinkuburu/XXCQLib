// Room: fantang.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.4.3
// 
// 

inherit ROOM;

void init();
int do_zhao(string);
void delete_served(object);

void create ()
{
        set ("short", "饭堂");
        set ("long", @LONG
这里是饭堂。因为炉子下的柴火不停的在燃烧的原因，所以这
里有点热。这里可是随时要提供伙食的。四周有不少人在吃饭，他
们不停的扒饭可能他们不愿把生命花费在吃饭上吧。东西两边都有
一个门口，西边是男休息室，东边室女休息室。
LONG);
        set("area","岭南");
	set("valid_startroom", 1);
        set("objects", ([
                __DIR__"npc/wenchifan" : 1,
        ]));

        set("exits", ([
                "south" : __DIR__"xiaojing",
                "east" : __DIR__"nvxiuxishi",
                "west" : __DIR__"nanxiuxishi",
        ]));
        setup();
}

void init()
{
        add_action("do_zhao", "zhao");
}

int do_zhao(string arg)
{

        object me;
        object chifan;

        if (!arg || (arg != "shou" && arg != "hand"))
	{
                return notify_fail("你要干什么？\n");	
        }
		
        me = this_player();	
        if( !objectp(chifan = present("wen chifan", environment(me))) )
                return notify_fail("你举起手，向厨房那边招了招手，发现那里没人理你。你是不是很无聊？\n");
	 	
        if( me->query_temp("marks/served") )
        {
                message_vision("温吃饭对$N说道：刚刚给你上过菜，这么快吃完，小心你的胃！\n", me);
                return notify_fail("");
        }

        message_vision("$N坐在桌前，举起手，向厨房那边招了招手，温吃饭快步走过来招呼你。\n", me);
 
        chifan->serve_tea(me) ;

        me->set_temp("marks/served", 1);
//      remove_call_out("delete_served");
        call_out("delete_served", 10, me);

        return 1;
}


void delete_served(object me)
{
      if ( objectp(me) ) me->delete_temp("marks/served");
}

int valid_leave(object me, string dir)
{
        if (dir == "west" && ((string)me->query("gender") =="女性") && !wizardp(me))
                return notify_fail("你怕不怕丑，一个大姑娘到男人们的地方去干吗？\n");

        if (dir == "east" && ((string)me->query("gender") =="男性") && !wizardp(me))
                return notify_fail("哎！你站住，你又想去别人闺房干吗？\n");

        if (  ((dir == "south") || (dir == "west") || (dir == "east") )
                && ( present("zhu", this_player())
                || present("tea", this_player()) || present("ji", this_player()) )
                && objectp(present("wen chifan", environment(me))) )
        switch ( random(2) ) 
        {
        case 0: 
                return notify_fail
                ("温吃饭向你嚷道：“你想拿我做的饭菜出去干什么，我做的饭菜可是很好吃的！”\n");
                break;
        case 1:
                message_vision("温吃饭飞身上来拦在你身前，放下我的菜，我可是不会把我的菜给外姓的人吃的。", me);
                return notify_fail("\n");
                break;
        }
	
        return ::valid_leave(me, dir);
}
