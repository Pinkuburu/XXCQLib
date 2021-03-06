// Condition: feixing_poison.c 毒字毒状态
// Created by Zeus 1999.4.30
// Modified by Zeus 1999.6.9
// 
// 

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        if( duration < 1 ) {
                tell_object(me, GRN "你觉得眼前的景物不在再有异样，身上的也不再疼痛。\n"+CYN+"你中的「飞行之毒」已经发作完了。\n" NOR );
                return 0;
        }

        if( !living(me) ) {
                message("vision", me->name() + "浑身颤抖，痛苦地哼了一声。\n", environment(me), me);
        } else {
                tell_object(me, HIB "你觉得眼前的景物正在晃动，原来你站都站不稳。\n"+RED+"你中的「飞行之毒」发作了！\n" NOR );
                message("vision", HIB + me->name() + "身子晃来晃去，似乎站不稳。\n",environment(me), me);
        }

        me->receive_wound("qi", random(75 - me->query_dex()));
        me->receive_wound("jingli", random(75 - me->query_dex()));0

        me->start_busy(3);

        me->apply_condition("feixing_poison", duration - 1);

        if ( (int)me->query_temp("powerup") ) {
                me->add_temp("apply/attack", - (int)(me->query_skill("force")/3));
                me->add_temp("apply/dodge", - (int)(me->query_skill("force")/3));
                me->delete_temp("powerup");
        }

        if( duration < 1 ) {
                tell_object(me, GRN "你觉得眼前的景物不在再有异样，身上的也不再疼痛。\n"+CYN+"你中的「上天下地、惟我独尊」已经发作完了。\n" NOR );
                return 0;
        }

        return CND_CONTINUE;
}
