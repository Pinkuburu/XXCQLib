// Room: shaozhan.c
// Created by Atlus 1999.7.21
// Modified by Atlus 1999.7.21
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "哨站");
        set ("long", @LONG
在这山势稍微平缓的小平台上，有一座不大的木屋，屋上猎猎飘扬的正
是飞鱼塘的“飞鱼旗”。你正感叹这美妙山景时，一队飞鱼弟子走了过来，
看来是正在巡逻布防，似乎发生了什么大事。从这里向东北便是第六峰了，
南面则是一个山谷。
LONG);
        set("area","飞鱼");
        set("outdoors", "feiyu");

        set("objects", ([
                __DIR__"npc/feiyudizi" : 2,
        ]));

        set("exits", ([
                "northeast" : __DIR__"diliufeng",
                "southdown" : __DIR__"shangu1",
        ]));
        setup();
        replace_program(ROOM);
}
