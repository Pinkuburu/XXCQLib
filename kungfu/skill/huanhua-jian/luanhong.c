// fenfei.c 满天花雨
 
#include <ansi.h>
 
inherit F_SSERVER;

int perform(object me)
{
	string msg;
	object weapon, target;
	object ob;
	int skill, skill2, ap, dp,qi_wound;

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = me->query_skill("sword");
	skill2 = me->query_skill("force");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("笨蛋，不使剑怎么能使「乱红飞过」？\n");

	if( !me->is_fighting()|| !living(me) )
	    	return notify_fail("「乱红飞过」只能在战斗中使用。\n");

	if( (int)me->query("max_neili") < 600 )
		return notify_fail("你的内力修为还不够高！\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你现在的内力不足！\n");

	if( skill < 135)
		return notify_fail("你浣花剑法的修为不够，不能使用「乱红飞过」! \n");

	if( skill2 < 90)
		return notify_fail("你九曲心法的修为不够，不能使用「乱红飞过」! \n");

	if( me->query_skill_mapped("sword") != "huanhua-jian") 
		return notify_fail("你没有激发浣花剑法，无法使用「乱红飞过」！\n");
	ob = me->query_temp("weapon");
 
	msg = HIY"$N突然一个闪身，越开一步，手中"+ob->query("name")+HIY"脱手而出，一式「乱红飞过」，带一声尖啸向$n的胸口飞射而去。\n\n"NOR;
	message_vision(msg, me, target);

	ap = ((me->query("combat_exp"))*(me->query_dex()));
	dp = ((target->query("combat_exp"))*(target->query_dex()))/2;
	if( dp < 1 )
		dp = 1;
	if( random(ap)*2 > dp && (random(100)<10))
	{
		me->add("neili",-300);
		msg = HIR "$n一个躲闪不及，"+ob->query("name")+HIR"在$n的身前穿胸而出，鲜血从伤口喷射而出，受的伤看来是极重的。\n\n"NOR;
		ob->move(target);
		message_vision(msg, me, target);
		qi_wound = skill*2 + random(skill*4);

		if(qi_wound > target->query("qi"))
			qi_wound = (target->query("qi") + 1);

		target->add("qi", -qi_wound);
		target->add("eff_qi", -(qi_wound/4));
		COMBAT_D->report_status(target, 0);
		me->start_busy(random(4));
	}
	else if( random(ap) > dp )
	{
		me->add("neili",-200);
		msg = HIR "$n努力的向旁一闪，"+ob->query("name")+HIR"总算没有穿中要害，但是$n受伤不轻，已然痛苦得汗如雨下了。\n\n"NOR;
		message_vision(msg, me, target);
		qi_wound = skill + random(skill*2);

		if(qi_wound > target->query("qi"))
			qi_wound = (target->query("qi") + 1);

		target->add("qi", -qi_wound);
		target->add("eff_qi", -(qi_wound/4));
		ob->move(target);
		COMBAT_D->report_status(target, 0);
		me->start_busy(random(4));
	}
	else
	{
		msg = HIG "只见$n不敢怠慢，一个铁板桥，腰就似折了一样，"+ob->query("name")+HIG"已然从头上飞掠了过去，好险哪！\n\n"NOR;
		message_vision(msg, me, target);
		me->add("neili",-100);
		destruct(ob);
		me->start_busy(2);
	}

	return 1;
}
