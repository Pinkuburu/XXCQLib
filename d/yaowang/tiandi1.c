// Room: 药王谷
// By 山猫adx @ 宁波小雪 17:00 99-10-26

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "田地");
	set("long", @LONG
这是药王谷用来种植草药的田地，你可以拿草药种籽在这里种植草药(zhong)。
等草药种成了就可以挖(dig)起来。
LONG );
	set("area", "药王谷");
	set("areb", "田地西");
	set("no_clean_up", 1);
	set("yaotian", 1);
	set("no_fight", 1);
	set("exits", ([
		"east" : __DIR__"yaowanggu",
	]));

	setup();
}

void init()
{
	add_action("do_dig", "dig");
//	add_action("do_work", "get");
}

int do_dig(string arg)
{
	object ob, me;
	me = this_player();

	if(me->query("party/party_name")!=HIB"药王谷"NOR
		|| me->query("party/level")<3 )
		return notify_fail("你不会种植草药！更不会挖草药！\n");

	if(me->is_fighting() && me->is_busy())
		return notify_fail("你很忙，没时间。\n");

	if( !arg || !ob = present(arg, environment(me)) )
		return notify_fail("指令格式：dig <草药ID> \n");

	if ( ob->query("dig")!=1 )
		return notify_fail("这个东西挖不起来啊？？\n");

	message_vision("$N轻轻将$n挖了起来。\n", me, ob);

	(environment(me))->add("yao",-1);
	me->improve_skill("healing", ((int)me->query_skill("healing",1)/2));
    ob->delete("no_get");
	ob->move(me);
	ob->delete("dig");
	return 1;
}

int do_work()
{
	if( (environment(this_player()))->query("yao")>=1 )
	{
	write("这里不能使用这个指令！\n");
	return 1;
	}
}
