// SKILL: wenguzhixin.c 温故知新
// Created by Zeus 1999.4.27
// Modified by Zeus 1999.5.28
// 修改描述。
// 原著武功所有人：无。自创。

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
        int lvl = (int)me->query_skill("zhixin", 1);

        if ( me->query("gender") == "无性" )
                return notify_fail("无根无性、阴阳不调、不男不女如何领会更高深的内功!\n");
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("「温故知新」只能通过学或运功(exert)中来增加熟练度!\n");
}

string exert_function_file(string func)
{
        return __DIR__"zhixin/" + func;
}