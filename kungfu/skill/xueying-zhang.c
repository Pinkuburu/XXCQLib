// xueying-zhang.c
// by mulan

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : RED"$N 使出血影掌的［血中魅影］，骤然间，一片刀光，一道血影，左右直扑$n！"NOR,
        "force" : 100,
        "dodge" : 15,
        "damage_type" : "瘀伤",
        "lvl" : 10,
        "skill_name" : "血中魅影"
]),
([      "action" : RED"$N 使出血影掌的［血衣漩尘］，身上的金红袈裟激扬起来，覆盖了$n的视线，$N的一双“血影手”，已戳向$n。"NOR,
        "force" : 120,
        "dodge" : 10,
        "damage_type" : "内伤",
        "lvl" : 20,
        "skill_name" : "血衣漩尘"
]),
([      "action" : RED"$N 马上知道$n变招，立时移开双手，却见［满天血影］，向$n扑去！"NOR,
        "force" : 140,
        "dodge" : 15,
        "damage_type" : "瘀伤",
        "lvl" : 10,
        "skill_name" : "满天血影"
]),
([      "action" : RED"$N 左右开弓，使出血影掌的［影随人行］，迅如鬼魅，大肚和尚渐感招架不来。    血影大师五指并伸，十指如戟，左右疾刺$n！"NOR,
        "force" : 160,
        "dodge" : 15,
        "damage_type" : "瘀伤",
        "lvl" : 10,
        "skill_name" : "影随人行"
]),
([      "action" : RED"$N左手挥起，掌心朝天，掌中带红，直奔$n,一招［血影腥风］使了出来! "NOR,
        "force" : 200,
        "dodge" : 20,
        "damage_type" : "瘀伤",
        "lvl" : 20,
        "skill_name" : "血影腥风"
]),
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; } 

int valid_combine(string combo) { return combo=="huoyan-dao"; }

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练血影掌必须空手。\n");
    if (me->query("shen") > 0 )
    	return notify_fail("你不是练邪门武功的料。 \n");
    if ((int)me->query_skill("strike",1) < 100)
        return notify_fail("你的基本掌法火候不够。\n");
    if ((int)me->query("max_neili") < 500)
        return notify_fail("你的内力太弱。\n");
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
    level = (int)me->query_skill("xueying-zhang", 1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 50)
       return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 50)
       return notify_fail("你的内力不够。\n");
    me->receive_damage("qi", 50);
    me->add("neili", -2);
    return 1;
}


