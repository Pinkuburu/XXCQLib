// SKILL: xuehuaforce.c 雪花心法
// god


inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
        if ( me->query("gender") == "无性" )
                return notify_fail("无根无性、阴阳不调、不男不女如何能领会更高深的内功!\n");
        
        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("你的基本内功火候还不够，还不能学习雪花心法。\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("「雪花心法」只能通过学习来增加熟练度!\n");
}

string exert_function_file(string func)
{
        return __DIR__"xuehuaforce/" + func;
}

