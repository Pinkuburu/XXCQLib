// made by lks;


inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
         int lvl=(int)me->query_skill("longmen-shengong",1);
        if ( me->query("gender") == "无性" && lvl > 49)
                return notify_fail("你无根无性，阴阳不调，难以领会高深的太极神功。\n");

        if ( me->query("class") == "bonze" )
                return notify_fail("龙门神功讲究杀气御敌，有违佛家之意，"
                        +RANK_D->query_respect(me)+"欲修此功，已是罪过。\n");

        if ((int)me->query_skill("force", 1) < 30)
                return notify_fail("你的基本内功火候还不够。\n");
         if (me->query_skill("yiqiguan-riyue",1)<120)
                  return notify_fail("你对本门内功--一气贯日月还领悟的不够。\n");

       return 1;
}

int practice_skill(object me)
{
        return notify_fail("龙门神功不能通过练习来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"longmen-shengong/" + func;
}

