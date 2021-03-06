// Exert: jieduother.c 
// Created by Zeus 1999.6.9
// Modified by Zeus 1999.6.9
// 遗留问题：如何判断这个人中了什么毒
// 

#include <ansi.h>

int exert(object me, object target)
{
        if(!living(target))
                return notify_fail("你怎么帮死人疗伤？\n");

        if ((int)me->query_skill("zhixin", 1) < 60)
                return notify_fail("你的「温故知新」修为还不够。\n");
        if( me->is_fighting() )
                return notify_fail("战斗中帮别人解毒？找死吗？\n");
        if( target->is_fighting() )
                return notify_fail("别人正在战斗，怎么帮别人解毒？\n");

        if ((int)me->query("neili") < 200 )
                        return notify_fail("你的内力不够，无法解毒。\n");

        if ((int)target->query("neili") < 100 )
                        return notify_fail("对方的内力不够，无法解毒。\n");

        target->apply_condition("feixinag_poison", 0);
        target->apply_condition("shengdu_poison", 0);
        target->apply_condition("xiangshi_poison", 0);
        target->apply_condition("duzun_poison", 0);

        message_vision(YEL"$N急点$n身上大穴，然后双手按在$n丹田，运起内功，$n口中吐出"+BLK"黑色浓血。\n"NOR,me,target);

        me->start_busy(1);
        me->add("neili",-200);
        target->add("neili",-100);
        target->start_busy(3);
        return 1;
}
