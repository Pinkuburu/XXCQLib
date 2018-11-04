// yangdu_poison.c 恙毒
// designed by lks


#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        if( duration < 1 ) return 0;
        if( !living(me) ) {
               message_vision("$N浑身颤抖，痛苦地哼了一声。\n", me);
        }
        else {
                tell_object(me, YEL "忽然觉得四肢无力，你中的恙毒发作了！\n" NOR );
               message_vision("$N的脸色突然惨白，发尖呈现出一点暗蓝色，好恐怖哦。\n"NOR, me);
        }
        me->receive_wound("qi",35 + random(10));
        me->receive_wound("jingli", 50);
        me->apply_condition("yangdu_poison", duration - 1);
        
       if( duration < 1 ) return 0;
       return CND_CONTINUE;
}
