
#include <ansi.h>
 
inherit F_SSERVER;

int perform(object me)
{
        string msg;
       object weapon,target;
         int skill,qi_wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = (me->query_skill("chixin-jian",1)+(me->query_skill("sword",1))/2);

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("不使剑怎么能使「苦海无边」？\n");

        if( !me->is_fighting()|| !living(me) )
                return notify_fail("「苦海无边」只能在战斗中使用。\n");

        if( (int)me->query("max_neili") < 500 )
                return notify_fail("你的内力修为还不够高！\n");

        if( (int)me->query("neili") < 200 )
                return notify_fail("你现在的内力不足！\n");

        if( skill < 120)
                return notify_fail("你慈心剑法的修为不够，不能使用「苦海无边」! \n");

        if( me->query_skill_mapped("sword") != "chixin-jian") 
                return notify_fail("你没有激发慈心剑法！\n");
 
        msg = HIY "$N双脚点地，猛的纵身一跃，离地有数丈只高，大喝一声“苦海无边”，\n忽然转身向下，朝着$n冲杀过去！\n\n"NOR;
        message_vision(msg, me, target);
 
        if ( ((random(me->query("combat_exp"))) > (target->query("combat_exp")/2)) || wizardp(me))
        {       
                if(userp(me))
                        me->add("neili",-200);

                msg = HIR "$n只觉得剑光点点，剑风阵阵，罩住了全身，无出可躲。\n\n"NOR;
                message_vision(msg, me, target);

                qi_wound = 100 + skill + random(skill*2);

                if(qi_wound > target->query("qi"))
                        qi_wound = (target->query("qi") + 1);

                target->add("qi", -qi_wound);
                target->add("eff_qi", -(qi_wound/4));

               target->start_busy(3+random(3));
               me->start_busy(2);
        }
        else
        {
                msg = HIG "只见$n脚一点地，向后急退数尺，堪堪躲过了这满天的剑影。\n\n"NOR;
                message_vision(msg, me, target);
                if(userp(me))
                        me->add("neili",-100);
                me->start_busy(3);
        }

        call_out("perform_hui", 8, me);
        return 1;
}

int perform_hui(object me)
{
        string msg;
        object weapon, target;
          int skill,qi_wound;

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return 0;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = (me->query_skill("chixin-jian",1)+(me->query_skill("sword",1))/2);
        
        if (me->query_skill_mapped("force")!="bairen-shengong" || me->query_skill("bairen-shengong",1)<100 )   return 0;

             if (!me->is_fighting())  return notify_fail("你没有进入战斗状态！\n");
        msg = HIY "\n$N脚尖刚刚沾地，借着上一招余势未衰，轻声禅唱“回头是岸”，\n呼的身行疾转一圈，手中剑一扬,借力横扫。\n\n"NOR;
        
        message_vision(msg, me, target);
        
        if ( ( (random(me->query("combat_exp"))) > (target->query("combat_exp")/3)) || (target->is_busy()) )
        {       
                if(userp(me))
                        me->add("neili",-200);

                msg = HIR "$n一惊，只见寒光一闪，已到了面门，无力招架 ！\n\n"NOR;
        
                message_vision(msg, me, target);

                qi_wound = 100 + skill;

                if(qi_wound > target->query("qi"))
                        qi_wound = (target->query("qi") + 1);

                target->add("qi", -qi_wound);
                target->add("eff_qi", -(qi_wound/4));

                me->start_busy(random(4));
        }
        else
        {
                msg = HIG "只见$n侧身一躲，避开了这雷霆万钧的一击。\n\n"NOR;
                message_vision(msg, me, target);
                if(userp(me))
                        me->add("neili",-100);
                me->start_busy(2);
        }

        
        return 1;
}


