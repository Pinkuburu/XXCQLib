//update by phoenix
#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
      if( duration < 1 )
      return 0;
      tell_object(me, HIR"突然你感觉胸口疼痛异常，刚才被万佛朝宗打中的肋骨处好象要裂开了似的，鲜血也从口中喷了出来！\n"NOR);
      tell_room(environment(me), HIR + me->name()+"突然哇得一声吐出口鲜血来,看来所中内伤不轻！\n" NOR,({ me }));
      me->receive_damage("qi", 300);
      me->receive_wound("qi", 100);
      me->apply_condition("dashouyin", duration - 1);
      if( duration == 1 )
        {
            if( 2 >=random(8))
           {
              me->unconcious();
              return 0;
           }
        }
   return CND_CONTINUE;
} 

