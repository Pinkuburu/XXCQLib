// menfang.c  门房
// mlf设计，lks编程

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short","花府大门");
	set("long",@LONG
这里是发党总部花府的大门，大门两侧耸立着两头青石狮子。大门上
方有一块横匾，上书“花府”两个大字，匾的左右垂下两个大红灯笼。大
门敞开着，由于发梦二党的子弟大多是京城的市井之徒，所以这里也就特
别热闹。
LONG
	);
	set("outdoors","huafu");
	set("valid_startroom",1);
	set("exits",([
                "enter" : __DIR__"huayuan",
                "north" : "/d/bianliang/huangkudajie4",
	]));
	set("objects",([
		__DIR__"npc/qi" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam,party;
        myfam=(mapping)me->query("family");
        party=(mapping)me->query("party");

        if( (!party || party["party_name"] != HIG "发梦二党" NOR) && ( !myfam || myfam["family_name"] != "发梦二党") 
                && (dir == "enter") )
        {
                if(objectp(present("qi lianxia", environment(me))))
                        return notify_fail("戚恋霞伸手拦住你谦声说道：发梦二党花府不容外人擅自入内，\n若非拜师的话"
                                + RANK_D->query_respect(me) +"还是请回去吧，免得自讨没趣。\n");
        }

        return ::valid_leave(me, dir);
}


