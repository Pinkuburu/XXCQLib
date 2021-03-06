// mlf设计，lks编程

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","温宅大门");
	set("long",
	"温府大门左右分据着两只玉石麒麟，通体墨绿，门额上一块黑色牌匾，
上书“温府”两个大字，气势非凡。门外是川流的人群，夹杂着小贩的吆
喝声，非常热闹。\n"
     	);
     	set("valid_startroom",1);
	set("outdoors","wenzhai");
     	set("exits",([
              "north" : "/d/bianliang/huangkudajie3",
     		"enter" : __DIR__"dating",
     	]));
      set("objects",([
              __DIR__"npc/long" : 1,
      ]));
	setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam,party;

             me=this_player();
             myfam=(mapping)me->query("family");
             party=(mapping)me->query("party");
	if( (!party || party["party_name"] != HIG "发梦二党" NOR) && ( !myfam || myfam["family_name"] != "发梦二党") 
                && (dir == "enter") )
        {
                if(objectp(present("long tuzhu", environment(me))))
                        return notify_fail("龙吐珠伸手拦住你谦声说道：发梦二党温宅不容外人擅自入内，\n若非拜师的话"
                                + RANK_D->query_respect(me) +"还是请回去吧，免得自讨没趣。\n");
        }

        return ::valid_leave(me, dir);
}
