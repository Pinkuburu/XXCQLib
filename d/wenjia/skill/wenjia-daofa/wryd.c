// 温柔一刀
// bye jfeng 江枫
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    object weapon;
    int damage;
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("温柔一刀只能对战斗中的对手使用。\n");
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
        return notify_fail("你使用的武器不对。\n");
    if( (int)me->query_skill("wenjia-daofa", 1) < 100 )
        return notify_fail("你的温家刀法不够娴熟，不会使用「温柔一刀」。\n");
    if( (int)me->query_skill("zhixin", 1) < 100 )
        return notify_fail("你的温故知新不够高，不能用[温柔一刀]。\n");
    if( (int)me->query("neili", 1) < 300 )
        return notify_fail("你现在内力太弱，不能使用「温柔一刀」。\n");
    msg = HIM "$N微微一笑，猛吸一口气,欲使出温柔一刀绝技攻击$n。\n"NOR;
    if( !target->is_killing(me) ) target->kill_ob(me);
    if (random(me->query_skill("force")) > target->query_skill("force")/5 )
    {
        target->start_busy( (int)me->query_skill("wenjia-daofa") / 30 + 1);
        damage = (int)me->query_skill("zhixin", 1);
        damage = damage +  (int)me->query_skill("qianli", 1);
        damage = damage +  (int)me->query_skill("wenjia-daofa", 1);
        target->receive_damage("qi", damage,me);
        target->receive_wound("qi", damage/2,me);
        me->add("neili", -damage);
        msg = HIR"只见$N手中$w越舞越快，幻起漫天刀光，倏的罩向$n,\n$n只觉漫天都是刀影，无从躲避，$N手中的$w已经穿过$n的心窝！！\n"NOR;
        me->start_busy(2);
    } else 
    {
        msg += CYN"可是$p猛地向前一跃,跳出了$P的攻击范围。\n"NOR;
        me->add("neili", -150);
        me->start_busy(4);
    }
    message_vision(msg, me, target);
    return 1;
}
