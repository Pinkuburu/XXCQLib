// SKILL: tianlongforce.c 金刚天龙功
// Created by Atlus 1999.7.22
// Modified by Atlus 1999.7.22
// 原著武功所有人：宋晚灯。

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
        if ( me->query("gender") == "无性" )
                return notify_fail("无根无性、阴阳不调、不男不女如何能领会更高深的内功!\n");
        
        if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够，还不能学习金刚天龙功。\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("「金刚天龙功」只能通过学习来增加熟练度!\n");
}

string exert_function_file(string func)
{
        return __DIR__"tianlongforce/" + func;
}
