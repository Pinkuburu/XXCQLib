//huaibao-tianxia.c
//by mulan

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([  "action" : HIY"$N身形一展，对着$n当胸就是一记“黑虎偷心"NOR,
    "force" : 320,
    "dodge" : 10,
    "damage": 50,
    "lvl"   : 0,
    "skill_name" : "黑虎偷心" ,
    "damage_type" : "瘀伤"
]),
([  "action" : HIY"$N身形一闪，一足踢向$n的心窝，便是“魁星踢斗"NOR,
    "force" : 380,
    "dodge" : 20,
    "damage": 80,
    "lvl"   : 20,
    "skill_name" : "魁星踢斗" ,
    "damage_type" : "瘀伤"
]),
([  "action" : HIY"$N身形一飘，往$n左肩一掌削出，便是“六丁开山"NOR,
    "force" : 440,
    "dodge" : 30,
    "damage": 100,
    "lvl"   : 40,
    "skill_name" : "六丁开山" ,
    "damage_type" : "瘀伤"
]),
([  "action" : HIY"$N身形一晃，一掌冲出，直扑$n的面门，便是“单龙出海"NOR,
    "force" : 520,
    "dodge" : 40,
    "damage": 150,
    "lvl"   : 60,
    "skill_name" : "单龙出海" ,
    "damage_type" : "瘀伤"
]),
([  "action" : HIY"$N身形一长，居高临下，向$n天灵劈下，便是“独劈华山"NOR,
    "force" : 620,
    "dodge" : 50,
    "damage": 200,
    "lvl"   : 100,
    "skill_name" : "独劈华山" ,
    "damage_type" : "瘀伤"
]),
});

// int valid_enable(string usage) { return usage=="strike" ||  usage=="hand" || usage=="finger" || usage=="claw" || usage=="cuff"; }
int valid_enable(string usage) { return usage=="unarmed";}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
            return notify_fail("练怀抱天下神功必须空手。\n");
	if (me->query_str() < 40)
		return notify_fail("你的臂力不够，不能练习这惊世的拳脚神功。\n");
        if ((int)me->query("max_neili") < 500)
            return notify_fail("你的内力太弱，无法练怀抱天下神功。\n");
	return 1;
}

string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action); i > 0; i--)
		if(level >= action[i-1]["lvl"])
			return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int) me->query_skill("huaibao-tianxia",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
            return action[NewRandom(i, 5, level/5)];

}
int practice_skill(object me)
{
	int skill;
	skill = me->query_skill("huaibao-tianxia",1);
	if ((int)me->query("qi") < 200)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 100)
		return notify_fail("你的内力不够练。\n");
 //改为和破山刀一致 adx
 //    if( environment(me)->query("no_fight") )
 //        return notify_fail("这里练功会误伤他人。\n");
 //    if( environment(me)->query("sleep_room") )
 //        return notify_fail("这里练功会打扰别人休息。\n");
        if(me->query("shen") < 10000)
		return notify_fail("练怀抱天下神功可是要有侠义精神才行。\n");
 //改为和破山刀一致 adx
     me->receive_damage("qi", 10);
     me->add("neili", -10);
	tell_room(environment(me), 
HIY"只见"+me->query("name")+"双手向天、缓缓向侧，左外旋右内转，双掌之间散发丝丝
白烟，慢慢的将地上的树叶和小枝都吸入掌中。随后双掌一收，朝内运气的，深深的呼气。\n"NOR);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 100 ) return 0;

	if( random(damage_bonus/2) > victim->query_str() ) {
		victim->receive_wound("qi", (damage_bonus - 100) / 2 );
                return HIR "扑的一声，$n竟被$N的怀抱天下神功震得口吐鲜血！\n" NOR;
	}
}

string perform_action_file(string action)
{
    return __DIR__"huaibao-tianxia/" + action;
}
