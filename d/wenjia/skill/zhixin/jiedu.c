// Exert: jiedu.c 
// Created by Zeus 1999.6.8
// Modified by Zeus 1999.6.9
// 遗留问题：如何判断这个人中了什么毒
// 

#include <ansi.h>

int exert(object me, object target)
{
        if ((int)me->query_skill("zhixin", 1) < 40)
                return notify_fail("你的「温故知新」修为还不够。\n");
        if( me->is_fighting() )
                return notify_fail("战斗中运功解毒？找死吗？\n");

        if ((int)me->query("neili") < 100 )
                        return notify_fail("你的内力不够，无法解毒。\n");

        me->apply_condition("feixing_poison", 0);
        me->apply_condition("shengdu_poison", 0);
        me->apply_condition("xiangshi_poison", 0);
        me->apply_condition("duzun_poison", 0);

        message_vision(YEL"$N急点身上大穴，然后运起内功，口中吐出"+BLK"黑色浓血。\n"NOR,me);

        me->add("neili",-100);

        me->start_busy(1);
        return 1;
}
