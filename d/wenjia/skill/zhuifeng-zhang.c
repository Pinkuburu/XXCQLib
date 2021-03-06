// 追风掌
// bye jfeng 江枫
inherit SKILL;
mapping *action = ({
([  "action" : "$N使一招[东风无力百花残],神态潇洒，出右掌扫抓向$n",
    "force" : 150,
    "lvl" : 10,
    "skill_name" : "东风无力百花残",
    "damage_type" : "内伤"
]),
([  "action" : "$N身行一变，左掌出一招[春风不度玉门关],攻向$n的$l",
    "force" : 250,
    "lvl" : 50,
    "skill_name" : "春风不度玉门关",
    "damage_type" : "内伤"
]),
([  "action" : "$N左踏一步，右踏一步，出一招[回首往事原如风],攻向$n的$l",
    "force" : 350,
    "lvl" : 100,
    "skill_name" : "回首往事原如风",
    "damage_type" : "内伤"
]),
([  "action" : "$N腾身而起，正是那[我随清风渐入梦],攻向$n的$l",
    "force" : 400,
    "lvl" : 150,
    "skill_name" : "我随清风渐入梦",
    "damage_type" : "内伤"
]),
([  "action" : "$N后退几步，忽然鬼魅般的转到$n的身后，双掌齐出，正是那一式[踏月追风虚飘渺]",
    "force" : 500,
    "lvl" : 300,
    "skill_name" : "踏月追风虚飘渺",
    "damage_type" : "内伤"
])
});
int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int practice_level(){   return 60;  }
int valid_combine(string combo) { return combo=="leiting-zhi"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("学追风掌必须空手。\n");
    if ((int)me->query("max_neili") < 100)
        return notify_fail("你的内力太弱，无法学追风掌。\n");
    if (me->query_skill("strike", 1) <=me->query_skill("zhuifeng-zhang", 1))
        return notify_fail("你的基础不够，无法领会更高深的技巧。\n");
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
    mapping a_action;
    int i, level;
    level   = (int) me->query_skill("zhuifeng-zhang",1);
    for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]){
                        a_action=action[NewRandom(i, 20, level/5)];
                       break;
                 }
    a_action["dodge"]  = 0-level;
    a_action["attack"]  = level/2;
    a_action["damage"] = level;
    return a_action;
}
int practice_skill(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练追风掌必须空手。\n");
    if ((int)me->query("qi") < 30)
        return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("你的内力不够练追风掌。\n");
    me->receive_damage("qi", 25);
    me->add("neili", -10);
    return 1;
}
string perform_action_file(string action)
{
    return __DIR__"zhuifeng-zhang/" + action;
}
