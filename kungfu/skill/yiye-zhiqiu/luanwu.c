// luanwu
#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	int damage;
	string msg;
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("神功杀敌只能对战斗中的对手使用。\n");
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用「乱」字诀！\n");		
	if( (int)me->query_skill("yiye-zhiqiu", 1) < 100 )
		return notify_fail("你的一叶知秋不够级别，不会使用「乱」字诀。\n");
	if( (int)me->query_skill("bairen-shengong", 1) < 50 )
		return notify_fail("你的百忍心法不够高，不能用来伤敌。\n");
	if( (int)me->query("neili", 1) < 300 )
		return notify_fail("你现在内力太弱，不能使用「乱」字诀。\n");
	msg = HIR "$N大喝一声,运起一叶知秋的「乱」字诀，朝$n猛扑过去!\n"NOR;
	if( !target->is_killing(me) ) target->kill_ob(me);
	if (random(me->query_skill("force")) > target->query_skill("force")/2 )
	{
		me->start_busy(3);
		target->start_busy(random(3));
		damage = (int)me->query_skill("bairen-shengong", 1);
                damage = damage + random(damage/2)+50;
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/3);
                me->add("neili", -damage);
		if( damage < 120 )
			msg += HIY"结果$n受到$N的乱舞之拳的攻击，闷哼一声。\n"NOR;
       else if( damage < 140 )
			msg += HIY"结果$n被$N的乱舞之拳一击，「嘿」地一声退了两步。\n"NOR;
        else if( damage < 180 )
			msg += RED"结果$n被$N的乱舞之拳一重击，胸口有如受到一记重锤，连退了五六步！\n"NOR;
		else
			msg += HIR"结果$n被$N的乱舞之拳击中，眼前一黑，象一捆稻草一样飞出去好几丈远！\n"NOR;
	}
	else 
	{
		target->start_busy(1);
		msg += CYN"可是$p看破了$P的企图，并没有上当。\n"NOR;
	}
	message_vision(msg, me, target);
	return 1;
}


