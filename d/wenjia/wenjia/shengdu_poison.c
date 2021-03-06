// Condition: shengdu_poison.c 声毒状态
// Created by Zeus 1999.5.11
// Modified by Zeus 1999.6.9
// 
// 

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        if( duration < 1 )  {
                tell_object(me, GRN "你觉得眼前的景物不在再有异样，身上的也不再疼痛。\n"+CYN+"你中的「声毒」已经发作完了。\n" NOR );
                return 0;
        }

        if( !living(me) ) {
                message("vision", RED + me->name() + "发出尖叫“啊”。\n"NOR, environment(me), me);
        } else {
                tell_object(me, YEL "你感觉到眼前的所有景物突然发亮…………  亮度慢慢减弱……，五脏六腑翻滚着。\n"+RED+"你中的「声毒」发作了。\n" NOR );
                message("vision", BLU + me->name() + "的身子微微的颤抖，用手捂着眼睛，马上又去捂着耳朵。\n"NOR,environment(me), me);
        }

        me->receive_wound("qi",random(50-me->query_con()));
        me->receive_wound("jingli",random(50 - me->query_con()));

        me->start_busy(3);

        me->apply_condition("shengdu_poison", duration - 1);

        if ( (int)me->query_temp("powerup") ) {
               me->add_temp("apply/attack", - (int)(me->query_skill("force")/3));
               me->add_temp("apply/dodge", - (int)(me->query_skill("force")/3));
               me->delete_temp("powerup");  }

        if( duration < 1 )  {
                tell_object(me, GRN "你觉得眼前的景物不在再有异样，身上的也不再疼痛。\n"+CYN+"你中的「声毒」已经发作完了。\n" NOR );
                return 0;
        }

        return CND_CONTINUE;
}
