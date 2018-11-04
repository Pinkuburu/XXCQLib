// xie_poison.c

#include <ansi.h>
#include <condition.h>

int update_condition(object me, int duration)
{
	if( duration < 1 ) return 0;
	me->receive_wound("qi", 10);
	me->receive_damage("jingli", 10);
	me->apply_condition("xie_poison", duration - 1);
	tell_object(me, HIB "你四肢一阵抽搐，你中的蝎毒发作了！\n" NOR );
	message("vision", me->name() + "四肢一阵抽搐，险些晕了过去！\n",environment(me), me);
	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}