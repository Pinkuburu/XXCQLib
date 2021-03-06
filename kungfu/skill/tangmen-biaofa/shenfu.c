// biao.c 			心有千千镖

#include <weapon.h>
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("心有千千镖" NOR, ({"biao"}));
	set_weight(50);

	if (clonep())
		set_default_object(__FILE__);
	else
	{
	        set("unit", "枚");
		set("long", "这是一枚四川唐门秘制的暗器，威力无比。\n");
		set("value", 0);
	}
        setup();
}

void init()
{
	add_action("do_perform","use");
}

int do_perform(string arg)
{
	object me, target;
	string msg;

	me = this_player();
	
	me->clean_up_enemy();
	target = me->select_opponent();

	if ( !arg || arg != "qian")
		return 0;
	
	if ( !(me->is_fighting()) )
		return notify_fail("心有千千镖只能在战斗中使用。\n");
 
	if( (int)me->query_skill("tangmen-qianbiao", 1) < 101 )
		return notify_fail("你的唐门暗器手法不够娴熟，无法使用心有千千镖。\n");

	if( (int)me->query("max_neili") < 1000  ) 
		return notify_fail("你的内力修为不够，无法使用心有千千镖。\n");

	if( (int)me->query_temp("xinqian") ) 
		return notify_fail("你忙于战斗，无法分神使用心有千千镖了。\n");

	if( (int)me->query("neili") < 800  ) 
		return notify_fail("你的内力不够。\n");

	msg = HIR"\n$N突然身行一止，从怀中摸出一枚手掌大小的暗器，一扬手向$n掷去。\n只见$n的周身飞舞着无数的光影，却听不到一丝声音。\n"NOR;
	message_vision(msg, me, target);
	me->add("neili", -500);
	me->set_temp("xinqian", 1);

	tell_object(target, HIR"\n你急忙屏气凝神，希望能够躲开这致命的一击。\n"NOR);
	target->start_busy(4);

	remove_call_out("effect_biao");
	call_out("effect_biao", 8, me, target);

	return 1;
}

int effect_biao(object me, object target)
{
	int myskill, trskill;
	string msg;

	myskill = (int) (2 * (int)me->query("dodge") + ((int)me->query("combat_exp") / 1000) + (int)me->uery_skill("tangmen-biaofa", 1));
	trskill = (int) (2 * (int)target->query("dodge") + ((int)target->query("combat_exp") / 1000));

	if ( ( myskill >= trskill ) && ( random(100) != 0 ) )
		{
			msg = HIR"忽然那无数的光影一闪而没，$n身行一顿，喷出一口鲜血，仰天而倒。\n"NOR;
			message_vision(msg, me, target);
			tell_object(target, HIR"你只觉得胸口一阵钻心的疼痛。低头一看只见那枚暗器已经深深的嵌在你的心口。\n血迹中隐约有几个小字[心有千千...]。"NOR);
			me->delete_temp("xinqian");
			me->start_busy(4);
			this_object()->move(target);
			target->unconcious();
		}
	else
		{
			tell_object(target, HIR"忽然那无数的光影一闪而没，你心中一惊急忙运内力于全身。\n"NOR);
			msg = HIR"$n双臂急舞，衣袖带起破风之声。只听当的一声轻响，竟将那枚暗器磕飞开去。\n"NOR;
			message_vision(msg, me, target);
			if ( target->query("neili") < 100 )
				target->set("neili", 0);
			else
				target->add("neili", -100);
			me->delete_temp("xinqian");
			me->start_busy(4);
			destruct(this_object());
		}
	return 1;
}