// shipo.c
// made by lks
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>


inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
         string msg;
        	
        if( !me->is_fighting() )
                return notify_fail("「石破天惊」只能在战斗中使用。\n");
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不对。\n");
		
        if( (int)me->query("neili") < 500 )
                return notify_fail("你的真气不够！\n");

          if( (int)me->query_skill("poshan-dao",1) < 80 )
                return notify_fail("你的破山刀法火候不够，无法使用「石破天惊」！\n");

         if( (int)me->query_skill("force",1) < 100 )
                return notify_fail("你的内功修为不够，无法使用「石破天惊」！\n");

        msg = HIM "$N"HIC"心如止水，无意之中使出了"HIR"“石破天惊”！\n" NOR;
        message_vision(msg, me);

        me->clean_up_enemy();
        ob = me->select_opponent();
        msg = HIR"石字决！\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        msg = HIY"破字决！\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        msg = HIC"天字决！\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        msg = HIW"惊字决！\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
          
        if (me->query_skill_mapped("force")=="bairen-shengong")
        {
               message_vision(HIR"$N只觉一尊天神从天而降，发须直立，吓得两腿发抖。\n"NOR,ob);
               ob->add("qi",(-1)*(me->query_skill("bairen-shengong",1)));
               ob->add("douzhi",-random(6));
               message_vision(CYN"$N的斗志下降了！！！\n"NOR,ob);
        }

        me->add("neili", -300);
        if( me->is_fighting() ) 
            me->start_busy(2+random(2));

        return 1;
}

