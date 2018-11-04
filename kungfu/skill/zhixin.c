// SKILL: wenguzhixin.c 温故知新
// Created by Zeus 1999.4.27
// Modified by Zeus 1999.4.27
// 
// 

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
        int lvl = (int)me->query_skill("zhixin", 1);

        if ( me->query("gender") == "无性" && lvl > 49)
                return notify_fail("你无根无性，阴阳不调，难以领会高深的温故知新。\n");
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("温故知新只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"zhixin/" + func;
}