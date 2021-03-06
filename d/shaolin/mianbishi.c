// Room: /d/shaolin/zhulin6.c
// Date: YZC 96/01/19

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "面壁石");
	set("long", @LONG
「面壁石」是达摩渡海东南来，登陆广州，梁武帝曾迎至金陵，唯达
摩释佛教教义，以静见性，为梁武帝所不能解，苹身渡江，于嵩山创立少
林寺，为禅宗之始。「面壁台」就是达摩在少林静修九年，面壁时留痕于
壁上，不但在历史上大大有名，更是武林中传说纷异少林武功绝学的发祥
地之所在。
LONG );
	set("valid_startroom", 1);

	set("exits", ([
		"north" : __DIR__"zhulin15",
	]));

	set("no_clean_up", 0);

	set("outdoors", "shaolin");

	setup();
}

void init()
{
	add_action("do_mianbi", "mianbi");
}

int do_mianbi()
{
	object me;
	mapping myfam;

	me = this_player();
	myfam = (mapping)me->query("family");

	if (me->is_busy())
		return notify_fail("你现在不能面壁参禅。\n");

	if (me->query("jingli") < 10)
		return notify_fail("你现在无法集中精力面壁参禅。\n");

	tell_object(me, "你面壁而坐，双目微阖，神气内敛，试图去感受三元归一、物我两忘的境界。\n");

	if ( me->query_skill("buddha",1) < 150
	|| me->query_skill("buddha",1) > 250)
		return 1;

	me->add("jingli", ( me->query("bac") - 11 ) / 5 - 4);

	if ( random(1000) < me->query("bac") )
	{
		tell_object(me, HIG"\n突然一瞬间你感到天地无限寂静、灵台一片空明，整个身心沉浸在一个通澈的世界，良久……\n"NOR);
		tell_object(me, HIG"你对禅宗心法的理解有了进一步的加深。\n\n"NOR);
		me->improve_skill("buddha", me->query("bac") * 3 );
		me->start_busy( 3 + random(5) );
		return 1;
	}

	return 1;
}
