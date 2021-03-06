// huanhua-jian.c 浣花剑法
// 平均damage:100 平均force:100 平均dodge:-5 平均parry:-5
// 铁线拳的特点在于威力一般，但招架和躲避均较难
// By Load

inherit SKILL;

mapping *action = ({
([	"action" : "$N手腕一抖一式「梅花三弄」，手中$w虚虚实实画出三朵梅花，突的合为一剑，刺向$n。",
    "damage" : 50,
	"parry"  : -10,
	"force"  : 30,
	"lvl"  : 0,
	"dodge"  : -10,
	"skill_name" : "梅花三弄",
	"damage_type" : "刺伤"
]),
([	"action" : "$N飞身在天，回手一式「满天星斗」，剑尖点出万点星光，直令$n觉得无从躲起。",
      "damage" : 100,
	"parry"  : -15,
	"force"  : 40,
	"lvl"  : 10,
	"dodge"  : -10,
	"skill_name" : "满天星斗",
	"damage_type" : "刺伤"
]),
([	"action" : "$N招式一缓，一式「无边落木」，$w带风雷之声自上而下斜劈下来，劈向$n的$l。",
      "damage" :120,
	"parry"  : 10,
	"force"  : 50,
	"lvl"  : 20,
	"dodge"  : 5,
	"skill_name" : "无边落木",
	"damage_type" : "砍伤"
]),
([	"action" : "$N手中$w向右斜引，将$n带向右侧，然后突然欺近$n，一式「移花劫玉」$w想$n疾刺过去。",
      "damage" : 150,
	"parry"  : -15,
	"force"  : 60,
	"lvl"  : 30,
	"dodge"  : -5,
	"skill_name" : "移花劫玉",
	"damage_type" : "刺伤"
]),
([	"action" : "$N剑意凄凉，一式「花落无凭」，$w忽左忽右，悠然而至，飘忽之间直奔$n的$l而去。",
      "damage" : 180,
	"parry"  : -10,
	"force"  : 70,
	"lvl"  : 40,
	"dodge"  : -5,
	"skill_name" : "花落无凭",
	"damage_type" : "刺伤"
]),
([	"action" : "$N踏上一步，手中$w似一条白练飞射而出，一式「长虹贯日」如射日之箭刺向$n。",
      "damage" : 200,
	"parry"  : 0,
	"force"  : 85,
	"lvl"  : 50,
	"dodge"  : 10,
	"skill_name" : "长虹贯日",
	"damage_type" : "刺伤"
]),
([	"action" : "$N手中$w“怆”然出手，剑意连绵，「天际长江」一式真如万里之长江，气势雄伟，有进无退。",
      "damage" : 220,
	"parry"  : 10,
	"force"  : 95,
	"lvl"  : 60,
	"dodge"  : -10,
	"skill_name" : "天际长江",
	"damage_type" : "刺伤"
]),
([	"action" : "$N身形急旋，跃到半空，使出「飞流直下」一式，连人带剑合身扑向$n。",
     "damage" : 250,
	"parry"  : 10,
	"force"  : 110,
	"lvl"  : 70,
	"dodge"  : 0,
	"skill_name" : "飞流直下",
	"damage_type" : "刺伤"
]),
([	"action" : "$N满场游走，忽近忽远，一式「孤帆远影」，一柄$w从前后左右不断刺向$n的$l。",
      "damage" : 280,
	"parry"  : -20,
	"force"  : 120,
	"lvl"  : 80,
	"dodge"  : -10,
	"skill_name" : "孤帆远影",
	"damage_type" : "刺伤"
]),
([	"action" : "$N略一点地，飞身而起，一式「九天银河」，$w自上而下带起一道白茫茫的剑气，劈向$n。",
      "damage" : 300,
	"parry"  : 10,
	"force"  : 130,
	"lvl"  : 90,
	"dodge"  : 0,
	"skill_name" : "九天银河",
	"damage_type" : "砍伤"
]),
([	"action" : "$N剑走轻灵、意走无形，一式「纤纤月影」悄无声的逼近$n，近在咫尺突然发力，向$n的$l刺了下去。",
      "damage" : 320,
	"parry"  : -10,
	"force"  : 140,
	"lvl"  : 100,
	"dodge"  : -10,
	"skill_name" : "纤纤月影",
	"damage_type" : "刺伤"
]),
([	"action" : "$N不顾$n的攻势，向前急冲，手中$w点出「点点星光」，将$n完全罩在了一片剑光之中。",
      "damage" : 350,
	"parry"  : -20,
	"force"  : 150,
	"lvl"  : 110,
	"dodge"  : -15,
	"skill_name" : "点点星光",
	"damage_type" : "刺伤"
]),
});

int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("你的内力不够。\n");
	if ((int)me->query_skill("jiuqu-xinfa", 1) < 20)
		return notify_fail("你的九曲心法火候不够。\n");
	return 1;
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("没有剑怎么练习浣花剑法？\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("你太累了，还是歇一会再练吧。。\n");
	me->add("jingli",-30);
	return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
		level   = (int) me->query_skill("huanhua-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

string perform_action_file(string action)
{
	return __DIR__"huanhua-jian/" + action;
}
