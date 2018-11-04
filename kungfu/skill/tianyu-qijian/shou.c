// 海天一线 shou.c
//Write by godzilla 11,14,99

#include <ansi.h>

inherit F_SSERVER;
void remove_effect(object me, int a_amount, int d_amount);
int perform(object me, object target)
{
	object weapon;
	int skill;
	string msg;

	if( !target ) target = offensive_target(me);
        if(!me->query("lingwu_perform"))
                return notify_fail("你还没有领悟其绝招。\n"); 
        if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「海天一线」只能在战斗中使用。\n");
       	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

    if( (int)me->query("int") < 25 )
		return notify_fail("天羽奇剑关键在于一个“悟字”,你悟性不够无法使用「海天一线」!\n");
	if( (int)me->query("max_neili") < 1000  ) 
		return notify_fail("你的内力不够。\n");
	if( (int)me->query_temp("tyqj_shou") ) 
		return notify_fail("你已经在运功中了。\n");
	skill = me->query_skill("tianyu-qijian");;
    msg = HIY"$N横剑一守，宛如海天一线，一道无形的屏障围绕在$N四周，\n这就是天下第一的守招----"+BLINK+HIR"海天一线"+NOR+HIY+"！！！\n"NOR;
	message_vision(msg, me, target);
         me->add_temp("apply/parry", 50)
;
	me->add_temp("apply/dodge", skill/3);
	me->set_temp("tyqj_shou", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 50,skill/3 :),20);

	me->add("neili", -100);
	if( me->is_fighting() ) me->start_busy(1);

	return 1;
}

void remove_effect(object me, int a_amount, int d_amount)
{
	me->add_temp("apply/parry", -a_amount);
	me->add_temp("apply/dodge", - d_amount);
	me->delete_temp("tyqj_shou");
	message_vision(HIY "$N一周天运功完毕，四周的剑气也慢慢散退。\n"NOR,me);
}
