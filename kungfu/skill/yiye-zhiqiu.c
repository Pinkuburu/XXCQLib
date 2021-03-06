// yiye-zhiqiu.c -一叶知秋
// designed by lks

inherit SKILL;
#include <ansi.h>

mapping *action = ({
([	"action" : "$N气凝如山，一式「白天黑叶」，双拳蓄势而发，击向$n的$l",
	"force" : 180,
	"dodge" : 5,
	"lvl" : 0,
	"skill_name" : "白天黑叶",
	"damage_type" : "内伤"
]),
([	"action" : "$N身形凝重，劲发腰背，一式「一叶成名」，缓缓向$n推出",
	"force" : 200,
	"dodge" : 5,
	"damage": 10,
	"lvl" : 20,
	"skill_name" : "一叶成名",
        "damage_type" : "内伤"
]),
([	"action" : "$N步伐轻灵，两臂伸舒如鞭，一式「叶叶不归」，令$n无可躲闪",
	"force" : 230,
	"dodge" : 15,
	"damage": 10,
	"lvl" : 30,
	"skill_name" : "叶叶不归",
        "damage_type" : "内伤"
]),
([	"action" : "$N身形跃起，一式「叶落归根」，双拳当空击下，势不可挡",
	"force" : 270,
	"dodge" : 5,
	"damage": 20,
	"lvl" : 40,
	"skill_name" : "叶落归根",
        "damage_type" : "内伤"
]),
([	"action" : "$N身形一矮，一式「叶来风雨」，两拳自下而上，攻向$n",
	"force" : 320,
	"dodge" : 10,
	"damage": 15,
	"lvl" : 50,
	"skill_name" : "叶来风雨",
        "damage_type" : "内伤"
]),
([	"action" : "$N身形一转，一式「枫叶飘飘」，攻向$n的身前身后",
	"force" : 380,
	"dodge" : 25,
	"damage": 25,
	"lvl" : 68,
	"skill_name" : "枫叶飘飘",
        "damage_type" : "内伤"
]),
([	"action" : "$N移形换位，步到拳到，一式「秋风扫叶」，四面八方都是拳影",
	"force" : 450,
	"dodge" : 15,
	"damage": 35,
	"lvl" : 95,
	"skill_name" : "秋风扫叶",
        "damage_type" : "内伤"
]),
([	"action" : "$N长啸一声，向前踏出一步，双拳中宫直进，一式「一叶知秋」，骤然击向$n的前胸",
	"force" : 530,
	"dodge" : 20,
	"damage": 50,
	"lvl" : 120,
	"skill_name" : "一叶知秋",
        "damage_type" : "内伤"
])
});

int valid_enable(string usage) { return  usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
         mapping myfam;
         myfam=(mapping)me->query("family");

          if ( (myfam) && (myfam["family_name"]!="发梦二党") )
                    return notify_fail("对不起，此项绝学不外传的。\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("练一叶知秋必须空手。\n");
       if ((int)me->query("shen") < 0)
            return notify_fail("一叶知秋不能被你用来为非作歹。\n");
        if ((int)me->query_skill("cuff", 1) < 30)
		return notify_fail("你的拳法火候不够，无法学一叶知秋。\n");
        if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力太弱，无法练一叶知秋。\n");
	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
	level   = (int) me->query_skill("yiye-zhiqiu",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("qi") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("你的内力不够练一叶知秋。\n");
        me->receive_damage("qi", 15);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"yiye-zhiqiu/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	object obb;
	if( damage_bonus < 100 ) return 0;
	if (!(obb = present("yeziye", this_player())) )  return 0;
        if( random(damage_bonus/2) > victim->query_str() ) {
                victim->receive_wound("qi", (damage_bonus - 100) / 2 );
                return WHT "你听到「哧」一声轻响一道白光伴着拳劲而来，忽然间$n血冒三丈，被$N铁叶所伤！\n" NOR;
        }
}
