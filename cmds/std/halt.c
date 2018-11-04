// halt.c
// By netkill@cctx 98-9-13

#include <ansi.h>

int main(object me, string arg)
{
	if (me->is_fighting()) {
		me->remove_all_enemy();
		message_vision("$N身形向后一跃，跳出战圈不打了。\n", me); 
		if(me->query_temp("biwu")) 
		shout(WHT"【江湖传闻】"+me->name()+"中途放弃比武！\n" NOR);
	}
	else if (!me->is_busy()) 
		return notify_fail("你现在不忙。\n");
	else if ((int)me->query_temp("pending/exercise") != 0) {
		message_vision("$N把正在运行的真气强行压回丹田，站了起来。\n", me);
		me->interrupt_me();
	}
	else if ((int)me->query_temp("pending/respirate") != 0){
		message_vision("$N把正在灵台中运行的先天之气徐徐吐出，睁眼站了起来。\n", me);
		me->interrupt_me();
	}
	me->interrupt_me();

	return 1;
}
	
