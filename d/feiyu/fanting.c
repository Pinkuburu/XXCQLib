// Room: fanting.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21

inherit ROOM;

void init();
int do_shake(string);
void delete_served(object);

void create()
{
	set("short", "饭厅");
	set("long", @LONG
这是飞鱼山庄的饭厅，厅内的摆设不多，只是几张大大的饭桌和的几
十把木凳。有几个人在吃饭，饭厅的南面有一个小窗，里面就是厨房了。
在这里的弟子们匆匆的进进出出，墙上写着：“吃饭请招手（shake hand)”。
LONG
	);

	set("no_fight", 1);
	set("valid_startroom", 1);
	set("objects", ([
                "/d/feiyu/npc/chuzi" : 1,
        ]));

       set("exits", ([
	          "north" :__DIR__"xiwuchang",
       ]));
       
	setup();
}
void init()
{
        add_action("do_shake", "shake");
}

int do_shake(string arg)
{

        object me;
        object chifan;

        if (!arg || (arg != "shou" && arg != "hand"))
        {
                return notify_fail("你要干什么？\n");	
        }
		
        me = this_player();	
        if( !objectp(chifan = present("chuzi", environment(me))) )
                return notify_fail("你举起手，向厨房那边招了招手，发现那里没人理你。看来你要过会再来了。\n");
	 	
        if( me->query_temp("fanmark") )
        {
                message_vision("厨子对$N说道：刚刚给你上过菜，这么快吃完了！新的还没好呢？\n", me);
                return notify_fail("");
        }

        message_vision("$N向厨房那边招了招手，厨子快步走过来招呼你。\n", me);
 
        chifan->serve_tea(me) ;

        me->set_temp("fanmark", 1);
        call_out("delete_served", 10, me);

        return 1;
}

void delete_served(object me)
{
        if ( objectp(me) ) me->delete_temp("fanmark");
}


int valid_leave(object me, string dir)
{
        object *obj;
        int i;

        me=this_player();

        if (  ((dir == "north") || (dir == "south") )
                && ( present("zhu", this_player())
                || present("tang", this_player()) || present("kaoya", this_player()) ))
        {
        message_vision("$N想起这里规定饭菜是不能带出饭厅的，就自动自觉的把想带出去的东西放下。\n", me);
        obj=all_inventory(me);
        for (i=0;i<sizeof(obj);i++){
                if (obj[i]->query("id")=="tang" || obj[i]->query("id")=="kaoya" ||
                    obj[i]->query("id")=="zhu" ) destruct(obj[i]);
                }
        }
        return ::valid_leave(me, dir);
}

