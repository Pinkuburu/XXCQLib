// wuxiang-shengong.c 少林 无相神功
// dts@xkx, cleansword@xkx

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
    if ( (int)me->query_skill("buddha", 1) < 20 && (int)me->query_skill("buddha", 1) <= (int)me->query_skill("wuxiang-shengong", 1))
		return notify_fail("你的禅宗心法领悟不够，无法领会更高深的无相神功。\n");

	if ( (int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够，无法领会无相神功。\n");

	return 1;
}


int practice_skill(object me)
{
	return notify_fail("无相神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"wuxiang-shengong/" + func;
}
