// Room: 药王谷
// By 山猫adx @ 宁波小雪 17:00 99-10-26

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "谷口");
	set("long", @LONG
这里是一个山谷的谷口，两边是高高的山峰，周围雾气缭绕，你只能看清几步
外，一条小路往北就进入了山谷，路边立着一块石碑(bei)。
LONG );
	set("area", "药王谷");
	set("areb", "谷口");
	set("exits", ([
		"north" : __DIR__"zhuangqian",
		"south" : __DIR__"shanlu2",
	]));
	set("item_desc", ([
		"bei" :  HIW"\n     ┏━━┓\n"+
		   HIW"     ┃ "HIB"药"HIW" ┃\n"+
		   HIW"     ┃ "HIB"王"HIW" ┃\n"+
		   HIW"     ┃ "HIB"谷"HIW" ┃\n"+
		   HIW"     ┃ "HIB"重"HIW" ┃\n"+
		   HIW"     ┃ "HIB"地"HIW" ┃\n"+
		   HIW"     ┃ "HIB"擅"HIW" ┃\n"+
		   HIW"     ┃ "HIB"闯"HIW" ┃\n"+
		   HIW"     ┃ "HIB"者"HIW" ┃\n"+
		   HIW"     ┃    ┃\n"+
		   HIW"     ┃ "HIR"杀"HIW" ┃\n"+
		   HIW"     ┃ "HIR"无"HIW" ┃\n"+
		   HIW"     ┃ "HIR"赦"HIW" ┃\n"+
		   HIW"     ┗━━┛\n"NOR,
	]));

        set("outdoors", "yaowang");
	setup();
	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        if( dir=="north" 
        && me->query("party/party_name")!=HIB"药王谷"NOR)
                return notify_fail(WHT"请看石碑！\n"NOR);
        return ::valid_leave(me, dir);
}
