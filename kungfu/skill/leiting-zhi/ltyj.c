// 雷霆指 [雷霆一击]
// bye jfeng 江枫
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        if( !target ) target = offensive_target(me);
        if((int)me->query_str() < 20)
                return notify_fail("你臂力不够,不能使用这一绝技!\n");
        if((int)me->query_skill("zhixin",1) < 100)
                return notify_fail("你温故知新的功力不够!\n");
        if((int)me->query_skill("finger") < 100)
                return notify_fail("你的指法修为不够!\n");
        if((int)me->query("neili") < 500)
                return notify_fail("你内力现在不够! \n");
        if((int)me->query("max_neili") < 400)
                return notify_fail("你内力修为不够! \n");
        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");
        msg =
HIM "$N使出雷霆指绝技「雷霆一击」，回过身来，背后竟似生了眼睛一般，左
手食中二指向$n接连戳去，$n不及攻敌，拼力躲避$N指力顿时动作大乱。\n";
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 4 )
        {
                msg +=  HIG "结果$p被$P指力点中几处穴道! \n" NOR;
                target->start_busy( (int)me->query_skill("leiting-zhi",1) / 20 + 2);
                me->add("neili", -150);
        }
        else
        {
                msg += HIM "$p情急智生，狠力一跃，退出老远。\n" NOR;
                me->start_busy(4);
        }
        return 1;
        message_vision(msg, me, target);
}
