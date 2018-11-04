// Room: shiyanshi.c
// Created by Zeus 1999.4.8
// Modified by Zeus 1999.7.22
// 
// 

inherit ROOM;
void create ()
{
        set ("short", "实验室");
        set ("long", @LONG
这里是小字号制造药品药方的实验室，房子里放着几张长桌子，长桌
上摆着很多瓶子和药品，桌旁有许多人在那里摆弄着瓶子药品。墙边有一
张书桌，上面有文房四宝，有人在那里记录实验过程。不时有人到北面的
资料室去取资料，也有人到东面的炼丹房制作实验品。
LONG);
        set("area","岭南");
        set("valid_startroom", 1);

        set("exits", ([
                "east" : __DIR__"liandanfang",
                "west" : __DIR__"dayuan",
                "north" : __DIR__"ziliaoshi",
        ]));

        set("objects", ([
                "/kungfu/class/wenjia/wenwen" : 1,
        ]));

        setup();
}

int valid_leave(object me, string dir)
{
        if ( (dir == "north" || dir == "east") && (int)me->query("wentask/done")<=200 )
                 return notify_fail("旁边闪出一名温家弟子拦住你，将眼一翻说：“那里是温家重地，你还没有资格进入呢!”\n");
        return ::valid_leave(me, dir);
}
