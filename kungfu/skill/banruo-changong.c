// banruo-changong.c 少林 般若禅功
// dts@xkx, cleansword@xkx

#include <ansi.h>
inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
	if ( (int)me->query_skill("buddha", 1) < 200 && (int)me->query_skill("buddha", 1) <= (int)me->query_skill("banruo-changong", 1))
		return notify_fail("你的禅宗心法领悟不够，无法领会更高深的般若禅功。\n");

	if ( (int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够，无法领会般若禅功。\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("般若禅功只能用学(learn)的来增加熟练度。\n");
}

void skill_improved(object me)
{
	switch (me->query_skill("banruo-changong",1))
	{
		case 60:
		{
			if (me->query("banruo-changong") < 1)
			{
				message_vision(HIR "$N盘膝坐下，双掌合十，头上已经渗出了一片汗珠。\n" NOR, me);
				tell_object(me, HIR "\n突然一股内息自丹田窜出，如脱缰的野马直冲百会而去! \n" NOR);
				tell_object(me, HIR "你清楚的知道般若禅功的修炼已经到了关键的时刻了！\n" NOR);
				tell_object(me, HIR "你努力的控制着内息，并试图突破现有的境界……\n\n" NOR);
				me->start_busy(25);
				call_out("over1", 20, me);
				break;
			}
			else break;
		}
		case 120:
		{
			if (me->query("banruo-changong") < 2)
			{
				message_vision(HIR "$N盘膝坐下，双掌合十，头上已经渗出了一片汗珠。\n" NOR, me);
				tell_object(me, HIR "\n突然一股内息自丹田窜出，如脱缰的野马直冲百会而去! \n" NOR);
				tell_object(me, HIR "你清楚的知道般若禅功的修炼已经到了关键的时刻了！\n" NOR);
				tell_object(me, HIR "你努力的控制着内息，并试图突破现有的境界……\n\n" NOR);
				me->start_busy(25);
				call_out("over2", 20, me);
				break;
			}
			else break;
		}
		case 180:
		{
			if (me->query("banruo-changong") < 3)
			{
				message_vision(HIR "$N盘膝坐下，双掌合十，头上已经渗出了一片汗珠。\n" NOR, me);
				tell_object(me, HIR "\n突然一股内息自丹田窜出，如脱缰的野马直冲百会而去! \n" NOR);
				tell_object(me, HIR "你清楚的知道般若禅功的修炼已经到了关键的时刻了！\n" NOR);
				tell_object(me, HIR "你努力的控制着内息，并试图突破现有的境界……\n\n" NOR);
				me->start_busy(25);
				call_out("over3", 20, me);
				break;
			}
			else break;
		}
	}
	return;
}

string exert_function_file(string func)
{
	return __DIR__"banruo-changong/" + func;
}

int over1(object me)
{
	if (random(100) < (90 * me->query("con") / 30))
	{
		tell_object(me, HIY "\n你运功相抗良久，突然一股清凉自会心冲百会将乱窜的真气导入正流。\n" NOR);
		tell_object(me, HIY "你感到了一种前所未有的舒畅，一时进入了物我两忘的境界……\n\n" NOR);
		tell_object(me, HIG "恭喜你！你的般若禅功已经达到了小般若神功的境界！！！\n" NOR);
		message_vision(HIG "$N长出了一口气，站了起来，如释重负。\n" NOR, me);
		me->add("max_neili",25);
		me->set("banruo-changong",1);
		return 1;
	}
	else
	{
		tell_object(me, HIB "\n你的努力没有一点效果，乱窜的真奇窜入了奇经八脉，你立时感到心痛似搅。\n" NOR);
		tell_object(me, HIB "你没能突破般若禅功的关键，你失败了！\n" NOR);
		tell_object(me, HIM "你的般若禅功功力下降了！！！\n\n" NOR);
		me->set_skill("banruo-changong",(int)me->query_skill("banruo-changong", 1) - 1);
		return 1;
	}
}

int over2(object me)
{
	if (random(100) < (75 * me->query("con") / 30))
	{
		tell_object(me, HIY "\n你运功相抗良久，突然一股清凉自会心冲百会将乱窜的真气导入正流。\n" NOR);
		tell_object(me, HIY "你感到了一种前所未有的舒畅，一时进入了物我两忘的境界……\n\n" NOR);
		tell_object(me, HIG "恭喜你！你的般若禅功已经达到了大般若神功的境界！！！\n" NOR);
		message_vision(HIG "$N长出了一口气，站了起来，如释重负。\n" NOR, me);
		me->add("max_neili",25);
		me->set("banruo-changong",2);
		return 1;
	}
	else
	{
		tell_object(me, HIB "\n你的努力没有一点效果，乱窜的真奇窜入了奇经八脉，你立时感到心痛似搅。\n" NOR);
		tell_object(me, HIB "你没能突破般若禅功的关键，你失败了！\n" NOR);
		tell_object(me, HIM "你的般若禅功功力下降了！！！\n\n" NOR);
		me->set_skill("banruo-changong",(int)me->query_skill("banruo-changong", 1) - 1);
		return 1;
	}
}

int over3(object me)
{
	if (random(100) < (60 * me->query("con") / 30))
	{
		tell_object(me, HIY "\n你运功相抗良久，突然一股清凉自会心冲百会将乱窜的真气导入正流。\n" NOR);
		tell_object(me, HIY "你感到了一种前所未有的舒畅，一时进入了物我两忘的境界……\n\n" NOR);
		tell_object(me, HIG "恭喜你！你的般若禅功已经达到了龙象般若神功的境界！！！\n" NOR);
		message_vision(HIG "$N长出了一口气，站了起来，如释重负。\n" NOR, me);
		me->add("max_neili", 25);
		me->add("con", 1);
		me->set("banruo-changong",3);
		return 1;
	}
	else
	{
		tell_object(me, HIB "\n你的努力没有一点效果，乱窜的真奇窜入了奇经八脉，你立时感到心痛似搅。\n" NOR);
		tell_object(me, HIB "你没能突破般若禅功的关键，你失败了！\n" NOR);
		tell_object(me, HIM "你的般若禅功功力下降了！！！\n\n" NOR);
		me->set_skill("banruo-changong",(int)me->query_skill("banruo-changong", 1) - 1);
		return 1;
	}
}