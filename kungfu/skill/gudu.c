// gudu.c 蛊毒之术
// By mulan

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me)
{
        if ((int)me->query_skill("poison", 1) < 100)
                return notify_fail("你的基本毒技火候不够，无法学蛊毒之术。\n");
        if ((int)me->query("max_neili") < 300)
                return notify_fail("你的内力太弱，无法学习蛊毒之术。\n");
        return 1;
}
int practice_skill(object me)
{
        return notify_fail("蛊毒之术只能靠学习来提高。\n");
}
