#include <ansi.h>
inherit FORCE;
int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
	if ( (int)me->query("kill") < 100)
		return notify_fail("血河派武功精要皆在一个“杀”字，你的杀气太低了。\n");
	if ( (int)me->query_skill("force", 1) < 20)
                return notify_fail("你的基本内功火候还不够，无法领会化血大法。\n");
	return 1;
}
int practice_skill(object me)
{
        return notify_fail("化血大法只能用学(learn)的来增加熟练度。\n");
}
string exert_function_file(string func)
{
        return __DIR__"huaxue-dafa/" + func;
}

