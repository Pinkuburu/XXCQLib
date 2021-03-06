// tianyu-shenfa.c 天羽身法

inherit SKILL;

mapping *action = ({
([
	"action" : "$n一式「随波逐流」，如同被凌厉的劲风摧垮，向后倒飞了一丈开外。\n",
]),
([
	"action" : "$n一式「如影随形」，竟如鬼魂一般在跟在$N身后，$N竟怎么也无法摆脱。\n",
]),
([
	"action" : "$n一式「移行换位」，$N的眼前竟没有了$n踪迹，一时呆在原地不知如何是好。\n",
]),
([
	"action" : "$n一式「急流勇进」，竟不顾$N的凌厉攻击，抢上前来。\n",
]),
([
	"action" : "$n一式「石沉大海」，身行突然一矮，待$N再看去却没有了踪影。\n",
])
});

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
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
//	action = query_action(ob, me);

	return action["action"];
//	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("qi") < 40 )
		return notify_fail("你的体力太差了，不能练天羽身法。\n");
	me->receive_damage("qi", 30);
	return 1;
}