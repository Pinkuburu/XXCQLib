// SKILL: duzi-du.c 毒字毒
// Created by Zeus 1999.4.27
// Modified by Zeus 1999.6.8
// 修改parry，dodge等值
// 原著武功所有人：温吐克、温吐马。

inherit SKILL;

mapping *action = ({
([	"action" : "$N伸出左手食指在额头上划了一横，正是“毒”字的第一划，一招「毒立三边静」",
//	"parry_action" : "",
	"damage" : 20,
	"parry"  : -5,
	"force"  : 20,
	"lvl"  : 0,
	"dodge"  : -5,
	"skill_name" : "毒立三边静",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N伸出左手中指在脸上划了一横，正是“毒”字的第二划。一招「毒钓寒江雪」",
//	"parry_action" : "",
	"damage" : 30,
	"parry"  : -10,
	"force"  : 30,
	"lvl"  : 20,
	"dodge"  : -10,
	"skill_name" : "毒钓寒江雪",
        "damage_type" : "伤害"
]),
([	"action" : "$N伸出左手无名指在脖子上划了一横，正是“毒”字的第三划。一招「毒书破万卷」",
//	"parry_action" : "",
	"damage" : 40,
	"parry"  : -15,
	"force"  : 40,
	"lvl"  : 40,
	"dodge"  : -15,
	"skill_name" : "毒书破万卷",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N伸出左手尾指在胸前划了一竖，正是“毒”字的第四划。一招「毒自莫凭栏」",
//	"parry_action" : "",
	"damage" : 50,
	"parry"  : -20,
	"force"  : 50,
	"lvl"  : 60,
	"dodge"  : -20,
	"skill_name" : "毒自莫凭栏",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N伸出右手母指在腹部上先划了一竖，再一横，正是“毒”字的第五划。一招「无毒不丈夫」",
//	"parry_action" : "",
	"damage" : 60,
	"parry"  : -25,
	"force"  : 50,
	"lvl"  : 80,
	"dodge"  : -25,
	"skill_name" : "无毒不丈夫",
        "damage_type" : "瘀伤"
]),
([	"action" : "$N伸出右手食指在空气中先划了一横，再一竖，接着一提，正是“毒”字的第六划。一招「最毒妇人心」",
//	"parry_action" : "",
	"damage" : 60,
	"parry"  : -25,
	"force"  : 50,
	"lvl"  : 80,
	"dodge"  : -25,
	"skill_name" : "最毒妇人心",
        "damage_type" : "内伤"
]),
([	"action" : "$N伸出右手中指在空气中划了一横，正是“毒”字的第七划。一招「毒字」",
//	"parry_action" : "",
	"damage" : 80,
	"parry"  : -35,
	"force"  : 70,
	"lvl"  : 120,
	"dodge"  : -35,
	"skill_name" : "毒字",
        "damage_type" : "内伤"
]),
([	"action" : "$N伸出右手无名指在空气中点了一下，正是“毒”字的第八划。一招「毒字毒」",
//	"parry_action" : "",
	"damage" : 100,
	"parry"  : -50,
	"force"  : 80,
	"lvl"  : 140,
	"dodge"  : -70,
	"skill_name" : "毒字毒",
        "damage_type" : "内伤"
]),
([	"action" : "$N伸出右手尾指很潇洒的点了一点，正是“毒”字的第九划。一招「毒」",
//	"parry_action" : "",
	"damage" : 120,
	"parry"  : -80,
	"force"  : 90,
	"lvl"  : 160,
	"dodge"  : -90,
	"skill_name" : "毒",
        "damage_type" : "内伤"
]),
});

int valid_enable(string usage) { return (usage == "lphand") || (usage == "parry");  }

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 200)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("lphand", 1) < 50)
                return notify_fail("你的「施毒手法」还不够熟练!\n");
        if ((int)me->query_skill("zhixin", 1) < 50)
                return notify_fail("「温故知新」等级不高时，会走火入魔的。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
		level   = (int) me->query_skill("duzi-du",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (objectp(weapon = me->query_temp("weapon")))
                return notify_fail("「毒字毒」是施毒的，不是使用武器的!\n");
        if ((int)me->query("qi") < 50)
                return notify_fail("你再练习就快昏了。\n");
        me->add("qi",-30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"duzi-du/" + action;
}

