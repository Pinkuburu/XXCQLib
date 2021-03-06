// heal.c

#include <ansi.h>

int exert(object me, object target)
{
	int skill;

	skill=me->query_skill("wuxiang-shengong",1);

	if ((int)me->query_skill("wuxiang-shengong", 1) < 60)
		return notify_fail("你的无相神功修为还不够。\n");

	if (((int)me->query("kill")/1000)<1)
		return notify_fail("你的杀气不足，无法运「喝杀」提高斗志。");

	if ((int)me->query("neili") < 200 || (int)me->query("max_neili") < 300 )
		return notify_fail("你的真气不够。\n");

	if (me->query_temp("sha"))
		return notify_fail("你刚运用完「喝杀」不久，现在用没有太大的效果。\n");

	message_vision(CYN"\n$N向西合十道：“出家人慈悲为怀。但佛有云：邪魔当道，亦可以杀止杀！”\n"NOR, me);
	message_vision(HIY"说罢猛一回头，大喝一声：“杀！杀！！杀！！！”霎时攻势更加猛烈，更加奋不顾身。\n"NOR, me);

	me->add("douzhi", me->query("kill")/1000);
	me->set_temp("sha",1);
	me->add("neili", -(me->query("kill")/150));

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me:), skill/3);

	return 1;
}

void remove_effect(object me)
{
	if ( (int)me->query_temp("sha") ) 
	{
		me->delete_temp("sha");
	}
}
