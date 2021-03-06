// jiangui.c
// from huanying.c

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
       object weapon;
       
    if( !target ) target = offensive_target(me);
 
       if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
          return notify_fail("你使用的武器不对,不能使出[剑鬼]。\n");

      if( !target || !me->is_fighting(target) )
      return notify_fail("「剑鬼」只能在战斗中对对手使用。\n");

    if((int)me->query_skill("tianlongforce", 1) < 100 )
    
		return notify_fail("你的金刚天龙功还不到家，不能呼唤[剑鬼]。\n");       
    
	if (me->query_skill_mapped("force") != "tianlongforce")
    
				return notify_fail("你所使用的内功不对。\n");
    
	if ((int)me->query_skill("feiyu-jian", 1) < 120 )
    
		return notify_fail("你的飞鱼剑法等级不够，不能呼唤[剑鬼]！\n");    
   
    if ( me->query_skill_mapped("sword") != "feiyu-jian"
        
		|| me->query_skill_mapped("dodge") != "fish-steps")
        
				return notify_fail("你必须用鱼形步法来配合飞鱼剑法,才能使出[剑鬼]！\n"); 
    
	if ((int)me->query("neili") < 360 )
           
		return notify_fail("你现在内力不足，不能呼唤[剑鬼]！\n");
       
	if ((int)me->query("max_neili") < 720 )
    
		return notify_fail("你的内力太弱，不能呼唤[剑鬼]！\n");
    
	if ( (int)me->query_temp("ghost", 1) ) 
    
		return notify_fail("你已经使出了[剑鬼]了！\n");
    
    message_vision(HIY"$N手中"+(string)weapon->query("name")+HIY"越使越快，突然无数剑光中出现了数个身形。这正是一式[剑鬼]!\n"NOR+
	               HIY"$n被其所迷惑，分不清哪个是真，哪个是假。\n"NOR, me, target);
  
              target->start_busy(2+random(4));
    me->add("neili", -(int)me->query_skill("feiyu-jian", 1) *3);    
    me->set_temp("ghost", 1);
    call_out("gone",7);
    return 1;
}

int gone()
{
    object me=this_player();
    message_vision("那个"HIY"剑鬼"NOR"于$N身旁晃了晃，又突然消失得无影无踪！\n", me);
    me->delete_temp("ghost");
    return 1;
}
