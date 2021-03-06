// 雷霆指
// bye jfeng 江枫
inherit SKILL;
mapping *action = ({
([      "action" : "$N左指挥出，一式「千钧一发」，削向$n的掌缘",
        "force" : 100,
        "dodge" : 5,
        "lvl" : 0,
        "skill_name" : "千钧一发",
        "damage_type" : "刺伤"
]),
([      "action" : "$N全身之力聚于一指，一式「十万火急」，指向$n的胸前",
        "force" : 140,
        "dodge" : 30,
        "lvl" : 15,
        "damage" : 25,
        "skill_name" : "十万火急",
        "damage_type" : "刺伤"
]),
([      "action" : "$N左掌贴于神道穴，右手一式「呼风唤雨」，向$n的$l划过",
        "force" : 180,
        "dodge" : 8,
        "lvl" : 25,
        "damage" : 55,
        "skill_name" : "呼风唤雨",
        "damage_type" : "刺伤"
]),
([      "action" : "$N双目怒视，一式「排山倒海」，双指拂向$n的额、颈、肩、臂、胸
、背",
        "force" : 220,
        "dodge" : 5,
        "damage": 85,
        "lvl" : 45,
        "skill_name" : "排山倒海",
        "damage_type" : "刺伤"
]),
([      "action" : "$N一式「笑指长空」，左掌掌心向外，右指蓄势点向$n的$l",
        "force" : 260,
        "dodge" : 15,
        "damage": 130,
        "lvl" : 60,
        "skill_name" : "笑指长空",
        "damage_type" : "刺伤"
]),
([      "action" : "$N双迸出无数道劲气，一式「雷霆急射」射向$n的全身",
        "force" : 400,
        "dodge" : 100,
        "damage": 200,
        "lvl" : 80,
        "skill_name" : "雷霆急射",
        "damage_type" : "刺伤"
]),
});
int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }
int practice_level(){   return 60;  }
int valid_combine(string combo) { return combo=="zhuifeng-zhang"; }
int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练雷霆指必须空手。\n");
//        if ((int)me->query_skill("zhixin", 1) < 50)
//                return notify_fail("你的温故知新火候不够。。\n");
        if ((int)me->query("max_neili") < 400)
                return notify_fail("你的内力太弱，无法练雷霆指。\n");
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
        level   = (int) me->query_skill("leiting-zhi",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
int practice_skill(object me)
{
        if ((int)me->query("jing") < 30)
                return notify_fail("你的精太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练雷霆指。\n");
        me->receive_damage("jing", 30);
        me->add("neili", -10);
        return 1;
}
string perform_action_file(string action)
{
    return __DIR__"leiting-zhi/" + action;
}
