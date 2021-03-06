// Condition: duzun_poison.c 惟我毒尊状态
// Created by Zeus 1999.5.11
// Modified by Zeus 1999.6.9
// 
// 

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{

        if( duration < 1 ) {
                tell_object(me, GRN "你觉得眼前的景物不在再有异样，身上的也不再疼痛。\n"+CYN+"你中的「上天下地、惟我独尊」已经发作完了。\n" NOR );
                return 0;
        }

        if( !living(me) )  message("vision", RED+me->name() + "身体剧烈抽搐，“啊”一声倒下。\n"NOR, environment(me), me);

        if(duration > 50 ) {
                tell_object(me, WHT "你感觉到眼前变得苍白一片，"+HIB+"全身皮肤却变得乌黑并且疼痛得禁不住而抽搐起来。\n"+RED+"你中的「上天下地、惟我独尊」发作了。\n" NOR );
                message("vision",  HIB + me->name() + "的全身变得乌黑，身子剧烈抽搐。\n"NOR, environment(me), me);
                me->receive_wound("qi",100-me->query_con());
                me->receive_wound("jingli",200-me->query_con());
                me->start_busy(4);
        } else if (duration >30 ) {
                tell_object(me, CYN "你感觉到眼前变得青绿一片，"+HIB+"全身皮肤却变得灰肿并且疼痛得禁不住而抽搐起来。\n"+RED+"你中的「上天下地、惟我独尊」发作了。\n" NOR );
                message("vision",  HIB + me->name() + "的全身变得灰肿，身子剧烈抽搐。\n"NOR, environment(me), me);
                me->receive_wound("qi",75-me->query_con());
                me->receive_wound("jingli",150-me->query_con());
                me->start_busy(3);
        } else if (duration >10 ) {
                tell_object(me, HIW "你感觉到眼前变得模糊一片，"+MAG+"全身皮肤却变得紫青并且疼痛得禁不住而抽搐起来。\n"+RED+"你中的「上天下地、惟我独尊」发作了。\n" NOR );
                message("vision",  MAG + me->name() + "的全身变得紫青，身子剧烈抽搐。\n"NOR, environment(me), me);
                me->receive_wound("qi",50-me->query_con());
                me->receive_wound("jingli",100-me->query_con());
                me->start_busy(2);
        } else {
                tell_object(me, YEL "你感觉到眼前景物晃动，全身疼痛得禁不住而抽搐起来。\n"+RED+"你中的「上天下地、惟我独尊」发作了。\n" NOR );
                message("vision",  BLK + me->name() + "的身子剧烈抽搐。\n"NOR, environment(me), me);
                me->receive_wound("qi",15 + random(10));
                me->receive_wound("jingli",10);
                me->start_busy(1);
        }

        me->apply_condition("duzun_poison", duration - 1);

        if ( (int)me->query_temp("powerup") ) {
               me->add_temp("apply/attack", - (int)(me->query_skill("force")/3));
               me->add_temp("apply/dodge", - (int)(me->query_skill("force")/3));
               me->delete_temp("powerup");  }

        if( duration < 1 ) {
                tell_object(me, GRN "你觉得眼前的景物不在再有异样，身上的也不再疼痛。\n"+CYN+"你中的「上天下地、惟我独尊」已经发作完了。\n" NOR );
                return 0;
        }

        return CND_CONTINUE;
}
