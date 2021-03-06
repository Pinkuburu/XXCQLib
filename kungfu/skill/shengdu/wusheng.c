// perform: wusheng.c 
// Created by Zeus 1999.5.11
// Modified by Zeus 1999.5.11
// Big Modified
// 
 
#include <ansi.h>
 
inherit F_SSERVER;

string status_msg(int ratio)
{
	if( ratio==100 ) return HIG "看起来充满活力，一点也不累。" NOR;
	if( ratio > 95 ) return HIG "似乎有些疲惫，但是仍然十分有活力。" NOR;
	if( ratio > 90 ) return HIY "看起来可能有些累了。" NOR;
	if( ratio > 80 ) return HIY "动作似乎开始有点不太灵光，但是仍然有条不紊。" NOR;
	if( ratio > 60 ) return HIY "气喘嘘嘘，看起来状况并不太好。" NOR;
	if( ratio > 40 ) return HIR "似乎十分疲惫，看来需要好好休息了。" NOR;
	if( ratio > 30 ) return HIR "已经一副头重脚轻的模样，正在勉力支撑著不倒下去。" NOR;
	if( ratio > 20 ) return HIR "看起来已经力不从心了。" NOR;
	if( ratio > 10 ) return RED "摇头晃脑、歪歪斜斜地站都站不稳，眼看就要倒在地上。" NOR;
	return RED "已经陷入半昏迷状态，随时都可能摔倒晕去。" NOR;
}

varargs void report_status(object ob)
{
	message_vision( "( $N" + status_msg(
		(int)ob->query("qi") * 100 / (int)ob->query("max_qi") ) 
		+ " )\n", ob);
}

int perform(object me)
{
        string msg;
	object weapon, target;
	object ob;
	int skill, skill2, ap, dp, neili_wound, qi_wound;

	me->clean_up_enemy();
	target = me->select_opponent();

        skill = (me->query_skill("shengdu",1)+(me->query_skill("lphand",1))/2);
	skill2 = (me->query_skill("zhixin",1)+(me->query_skill("force",1))/2);

        if( !me->is_fighting() || !living(me) )
                return notify_fail("「无声之毒」只能对战斗中的对手使用。\n");
 
        if (!present("gubo", me))
                return notify_fail("「无声之毒」必须有古钹才能使用。\n");

        if( skill < 100)
                return notify_fail("你的「声毒」等级不够, 不能使用「无声之毒」！\n");

        if( me->query("neili") < 200 )
                return notify_fail("你的内力不够，无法运用「无声之毒」！\n");
 
        msg = HIC "$N从怀里掏出一个古钹。\n钹只是乐器，既非武器，也不是暗器，更不是毒物。\n$N只是扬钹、交错、发声而已。但双钹一交。星火直冒。然而钹却无声。不响。静。寂。寂静的如一场涅磐。无声。没有声音。\n"NOR;
        message_vision(msg, me, target);

	ap = ((me->query("combat_exp"))*(me->query_dex()));
	dp = ((target->query("combat_exp"))*(target->query_dex()))/2;
	if( dp < 1 )
		dp = 1;
	if( random(ap)*2 > dp && (random(100)<10))
	{
		if(userp(me))
			me->add("neili",-100);

                msg = HIR "$n见到$N扬钹，急忙捂耳。双钹在霎那间炸起7682道金光，比蛛丝还细，比针尖还利，比蜂雨还密集，急射向$n，$n躲避不及，正中心口，$n看起来已经死了。\n"NOR;
		message_vision(msg, me, target);
                target->die();
		me->start_busy(random(6));
	}
	else if( random(ap) > dp )
	{
		if(userp(me))
			me->add("neili",-100);

                msg = HIR "$n见到$N扬钹，急忙捂耳。双钹在霎那间炸起7682道金光，比蛛丝还细，比针尖还利，比蜂雨还密集，急射向$n，$n努力的向旁一闪，正中$p，$n咬了咬牙，已然痛苦得汗如雨下了。\n"NOR;
		message_vision(msg, me, target);
		qi_wound = skill + random(skill*2);

		if(qi_wound > target->query("qi"))
			qi_wound = (target->query("qi") + 1);

		target->add("qi", -qi_wound);
		target->add("eff_qi", -(qi_wound/4));
                target->apply_condition("shengdu_poison", random(me->query_skill("shengdu")/10) + 1 + me->query_condition("shengdu_poison"));
		report_status(target);
		me->start_busy(random(6));
	}
	else
	{
		msg = HIG "只见$n不敢怠慢，捂耳，护心，躲避，金光从$n身旁后飞过。\n"NOR;
		message_vision(msg, me, target);
		if(userp(me))
			me->add("neili",-100);
		me->start_busy(3);
	}

	return 1;

}
