// shunxi-qianli.c 瞬息千里
// 瞬息千里是小寒山派的轻功，特点是姿势优美，效果明显
// 无特殊应用

inherit SKILL;

mapping *action = ({
([	"action" : "$n双袖迎风，飘身而起，瞬间已经退出了三丈有余，$N的招式也就自然落了空。\n",
	"dodge"  : 15
]),
([	"action" : "$n身形急转，左一转，右一转，轻轻巧巧的将$N的攻势卸在一边。\n",
	"dodge"  : 30
]),
([	"action" : "$n快步慢走，疾步缓行，看似随意的几步竟已走到了战局之外。\n",
	"dodge"  : 45
]),
([	"action" : "$n左足一点，身形扶摇直上，却在半空中一个转折，轻飘飘地落在了$N身后。\n",
	"dodge"  : 60
]),
([	"action" : "但是$n不慌不忙，身子如行云流水般往后一飘...再一飘，早避到了五尺开外。\n",
	"dodge"  : 75
]),
([	"action" : "$n不进不退，身形只是稍稍一转，宛若一道轻风般从$N身边掠过。\n",
	"dodge"  : 90
]),
([	"action" : "$n不退反进，在$N惊诧之际已然稳稳站在$N身后丈外。\n",
	"dodge"  : 105
]),
([	"action" : "$n脚步急点，身形微动，$N眼前一花已然不见了$n的踪影。\n",
	"dodge"  : 120
])
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("shunxi-qianli");

	if (level < 80 )
		zhaoshu--;

	if (level < 60 )
		zhaoshu--;

	if (level < 40 )
		zhaoshu--;

	return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
	return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(string limb)
{
	object me, ob;
	mapping action;

	me = this_player();
	action = query_action(me, ob);

	return action["action"];
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 40 )
		return notify_fail("你的体力太差了，不能练瞬息千里。\n");
	me->receive_damage("qi", 30);
	return 1;
}