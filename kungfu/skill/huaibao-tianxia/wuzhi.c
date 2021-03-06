// bao.c  怀抱天下之「五指连心」
// Modified by Venus Oct.1997

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;

    if( !target ) target = offensive_target(me);
    if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「五指连心」只能对战斗中的对手使用。\n");

    if( (int)me->query_skill("huaibao-tianxia", 1) < 100 )
        return notify_fail(WHT"你的怀抱天下神功不够，还使不出「五指连心」。\n"NOR);

    msg = HIC "$N低声呼吼，类似兽物在喉咙里咆哮一般，忽然身形变错起来。  \n"NOR;
     msg += HIC"$N陡然站定。$N的双手，忽然张开，然后慢慢屈起第一节手指，\n"NOR;
    msg += HIC"逐而又屈起了第二节手指，再一起屈起了第三节的手指，这时手掌已变成了：拳头！\n"NOR;
    msg +=HIW"只听$N叱喝道：“五指连心，五瓣成莲！\n\n\n"NOR;


    if (random(me->query_skill("force")) > target->query_skill("force")/3||
random(me->query("combat_exp")) > (int)target->query("combat_exp")/4 )
    {
        me->start_busy(2);
        damage = (int)me->query_skill("huaibao-tianxia", 1);

        damage = damage + random(damage);

        target->set("qi", target->query("qi")/2);
        target->receive_wound("qi", damage);
        target->receive_damage("jingli", damage*2/3);
        target->receive_wound("jingli", damage/2);
        target->set("neili", target->query("neili")/2);
        me->add("neili", -damage/2);
    msg +=RED"但见$n哇的一声,被$N巨大的拳头大的飞出丈许！\n"NOR;

    } else
    {
        me->start_busy(4);
        msg += HIY"可是$p看破了$P的企图，闪身护头躲在了一边。\n"NOR;
    }
    message_vision(msg, me, target);

    if(userp(target)) target->fight_ob(me);
//    else if( !target->is_killing(me) ) target->kill_ob(me);
    return 1;
}
