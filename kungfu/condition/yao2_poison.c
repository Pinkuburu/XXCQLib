
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	if( duration < 1 ) return 0;
	if( !living(me) ) {
	message("vision", me->name() + "痛苦地呻吟了一声。\n", environment(me), me);
	}
	else {
	tell_object(me, BLU "忽然你感到一阵颤抖，你所中的小五毒之气发作了！\n" NOR );
	message("vision", BLU+me->name() + "的脸色突然一明一暗，连变五次。\n" NOR ,
	environment(me), me);
	}
	me->receive_wound("qi",5 + random(10));
	me->receive_wound("jingli", 5);
	me->apply_condition("wudu_poison", duration - 1);
	if ( (int)me->query_temp("powerup") ) {
		me->add_temp("apply/attack", - (int)(me->query_skill("force")/2));
		me->add_temp("apply/dodge", - (int)(me->query_skill("force")/2));
		me->delete_temp("powerup");
	}

	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}
