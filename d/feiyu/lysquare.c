// Room: lysquare.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "飞鱼山庄广场");
        set ("long", @LONG
这里是"飞鱼塘飞鱼山庄"的大广场，山中一个人造的大平台使这里
形成一个巨大的广场。广场的中央是方园约十丈的花池，各色的鲜花在
池中争香吐艳。五色的鲤鱼与碧绿的浮萍相互辉映，赏心悦目。花池的
中央是一条大石柱，石柱上刻着九条龙。龙首向四面伸展，宏伟壮观。
LONG);
        set("area","飞鱼");
        set("outdoors", "feiyu");
        set("valid_startroom", 1);

        set("objects", ([
                "/d/feiyu/npc/feiyudizi" : 2,
        ]));

        set("exits", ([
                
                "north" : __DIR__"qianting",
                "westdown" :__DIR__"shanlu1",
        ]));

        setup();

        
}

int valid_leave(object me, string dir)
{
        if ((!(string)me->query("family") || (string)me->query("family/family_name") != "飞鱼塘") 
               && ( dir == "north" )
              && (objectp(present("dizi", environment(me)))
               || objectp(present("dizi", environment(me))) ))
               {  if (objectp(present("dizi", environment(me)))) 
               
                       return notify_fail("飞鱼弟子喝道：你不是飞鱼塘弟子，不得入内。\n");
               else
                       return notify_fail("飞鱼弟子喝道：你不是飞鱼塘弟子，不得入内。\n");
               
        }

        return ::valid_leave(me, dir);
}
