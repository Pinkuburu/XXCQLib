// Room: square.c
// Created by Zeus 1999.3.26
// Modified by Zeus 1999.4.17
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "总部广场");
        set ("long", @LONG
这里是"岭南老字号"温家总部“大字号”前面的广场。向前
看去是一座宏伟的建筑，它的宏伟也代表了温家的庞大和温家在
武林中的地位广场四周插满了旗帜，每个旗帜周围都有一个人守
卫着。向北走可以进入前厅，而东西方向上也是一个小广场。
LONG);
        set("area","岭南");
        set("outdoors", "wenjia");
	set("valid_startroom", 1);

        set("objects", ([
                __DIR__"npc/wendating" : 1,
                __DIR__"npc/wenxiaoting" : 1,
        ]));

        set("exits", ([
                "down" : __DIR__"paifang",
                "north" : __DIR__"qianting",
                "west" : __DIR__"westsquare",
                "east" : __DIR__"eastsquare",
        ]));
        setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "老字号温家") && dir == "north" && dir == "east" && dir == "west" 
               && !wizardp(me) && !present("wenjiacard", this_player()) &&
               (objectp(present("wen dating", environment(me)))
               || objectp(present("wen xiaoting", environment(me))) ))
               {  if (objectp(present("wen dating", environment(me)))) 
               
                       return notify_fail("温大听喝道：你不是温家弟子，不得入内。\n");
               else
                       return notify_fail("温小听喝道：你不是温家弟子，不得入内。\n");
               
        }

        if ( present("wenjiacard", this_player()) &&
             objectp(present("wen dating", environment(me))) ) 
                message_vision("温大听对$N恭敬地说道：原来是温家的客人，请进，请进！\n", me);
        if ( present("wenjiacard", this_player()) &&
             objectp(present("wen xiaoting", environment(me))) ) 
                message_vision("温小听对$N恭敬地说道：原来是温家的客人，请进，请进！\n", me);

        return ::valid_leave(me, dir);
}
