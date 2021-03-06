// heal.c	heal for tianyu-xinfa by winder

#include <ansi.h>

int exert(object me, object target)
{
	if ( (string)target->query("id") == (string)me->query("id") )
	{
		if ((int)me->query_skill("tianyu-xinfa", 1) < 20)
			return notify_fail("你的天羽心法修为还不够。\n");

		if( me->is_fighting() )
			return notify_fail("战斗中运功疗伤？找死吗？\n");
	
		if( (int)me->query("neili") < 50 )
			return notify_fail("你的真气不够。\n");

		if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
			return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

		if( ((int)me->query("eff_qi") == (int)me->query("max_qi")) && ( (int)me->query("qi") == (int)me->query("eff_qi") ))
			return notify_fail("你现在不需要运功治疗！\n");

		write( HIW "你全身放松，坐下来开始运功疗伤。\n" NOR);
		message("vision",HIW + me->name() + "吐出一口瘀血，脸色看起来好多了。\n" NOR,environment(me), me);
	
		me->receive_curing("qi", 10 + (int)me->query_skill("force")/5 );
		me->add("neili", -50);
		me->set("jiali", 0);
		me->start_busy(1);

		return 1;
	}
	else
	{
		if( !objectp(present(target, environment(me))) || !living(target) )
			return notify_fail("这里没有这个人。\n");
		
		if ((int)me->query_skill("tianyu-xinfa", 1) < 20)
			return notify_fail("你的天羽心法修为还不够。\n");

		if( me->is_fighting() || target->is_fighting())
			return notify_fail("战斗中无法运功疗伤！\n");

		if( (int)me->query("max_neili") < 100 )
			return notify_fail("你的内力修为不够。\n");

		if( (int)me->query("neili") < 100 )
			return notify_fail("你的真气不够。\n");

		if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
			return notify_fail( target->name() + "已经受伤过重，经受不起你的真气震荡！\n");

		if( ((int)target->query("eff_qi") == (int)target->query("max_qi")) && ( (int)target->query("qi") == (int)target->query("eff_qi") ))
			return notify_fail( target->name() + "现在不需要运功治疗！\n");

		message_vision(HIY "$N坐了下来运起内功，将手掌贴在$n背心，缓缓地将真气输入$n体内....\n过了不久，$N额头上冒出豆大的汗珠，$n吐出一口瘀血，脸色看起来红润多了。\n" NOR,	me, target);

//		target->receive_curing("qi", 10 + (int)me->query_skill("force")/3 );
		target->add("qi", 10 + (int)me->query_skill("force")/3 );
		target->add("jingli", 10 + (int)me->query_skill("force")/3 );

		if( (int)target->query("eff_qi") < (int)target->query("max_qi") )
			target->set("eff_qi", (int)target->query("eff_qi") + (int)target->query("max_qi")/20);

		if( (int)target->query("eff_qi") > (int)target->query("max_qi") )
			target->set("eff_qi", (int)target->query("max_qi"));

		if( (int)target->query("jingli") > (int)target->query("eff_jingli") )
			target->set("jingli", (int)target->query("eff_jingli"));

		if( (int)target->query("qi") > (int)target->query("eff_qi") )
			target->set("qi", (int)target->query("eff_qi"));

		me->add("neili", -100);
		me->set("jiali", 0);
		me->start_busy(2);
		target->start_busy(1);

		return 1;
	}
}