// tianyu-shenfa.c 浣花身法
// By Load

inherit SKILL;

mapping *action = ({
([	"action" : "$n不退反进，身形灵动,一式「源头活水」，竟然从$N的凌厉攻势中“流”了过去。\n",
]),
([	"action" : "$n单掌拍出满天掌影，一式「无尽碧莲」，却是佯攻反退，人早已闪在了一边。\n",
]),
([	"action" : "$n一式「落英缤纷」，身形陡起数丈，然后斜斜落下，$N已然追之不及了。\n",
]),
([	"action" : "$n身形急旋，一式「幻眼云烟」，霎时$n竟然从$N眼前凭空消失，无影无踪。\n",
]),
([	"action" : "$n左一步、右一步，伏身急走，一式「清流人间」，竟然奇迹般的到了$N的背后。\n",
]),
([	"action" : "$n不避不闪，一式「浣溪飞花」，借敌之力，御风而行，飘到了丈许之外。\n",
])
});

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int valid_enable(string usage)
{
	return usage == "dodge";
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
	if( (int)me->query("jingli") < 50 )
		return notify_fail("你的体力太差了，不能练浣花身法。\n");
	me->receive_damage("jingli", 25);
	return 1;
}