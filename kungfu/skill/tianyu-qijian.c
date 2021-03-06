// 天羽奇剑 tianyu-qijian.c 
// write by godzilla 1999.11.5

#include <ansi.h>
inherit SKILL;
mapping *action =
({([
        "action" : "$N一招「倒挂金钩」，右手举起$w，夹杂着阵阵风声向$n刺去",
        "skill_name" : "倒挂金钩",
        "force" : 100,
        "dodge" : -10,
        "lvl" : 0,
        "damage" : 50,
        "damage_type" : "刺伤",
]),
([      "action" : "$N将手中$w直竖，往天一指，随后反剑刺向$n的$l,这招正是天羽奇剑的起手势「指天一剑」",
        "skill_name" : "指天一剑",
        "force" : 110,
        "dodge" : -10,
        "lvl" : 10,
        "damage" : 55,
        "damage_type" : "刺伤",
]),
([      "action" : "只见$N手中$w一紧，一招「梅花三弄」向$n刺了过去",
        "skill_name" : "梅花三弄",
        "force" : 120,
        "dodge" : -20,
        "lvl" : 20,
        "damage" : 60,
        "damage_type" : "刺伤",
]),
([      "action" : "$N随手用一招「开道斩蛇」向$n缓缓的刺了过去",
        "skill_name" : "开道斩蛇",
        "force" : 130,
        "dodge" : -10,
        "lvl" : 30,
        "damage" : 75,
        "damage_type" : "刺伤",

]),
([      "action" : "$N一声冷笑，一招「天河倒泻」以排山倒海之势飞向$n的$l",
        "skill_name" : "大吉祥光明势",
        "force" : 140,
        "dodge" : -10,
        "lvl" : 40,
        "damage" : 80,
        "damage_type" : "刺伤",
]),

([      "action" : "$N握着$w，心志一豪，一剑「长虹贯日」平直刺出",
        "skill_name" : "长虹贯日",
        "force" : 150,
        "dodge" : -10,
        "lvl" : 50,
        "damage" : 80,
        "damage_type" : "刺伤",
]),

([      "action" : "$N突然向后退了一大步，稍拉远距离，一招「三潭印月」，递了出去",
        "skill_name" : "三潭印月",
        "force" : 160,
        "dodge" : -5,
        "lvl" : 60,
        "damage" : 80,
        "damage_type" : "刺伤",
]),
([      "action" : "$N提一口真气，使出「漫天风雪」，手中$w上下翻飞，犹如飘雪般刺向$n，叫$p再也分不清哪个是真，哪个是假",
        "skill_name" : "漫天风雪",
        "force" : 170,
        "dodge" : -5,
        "lvl" : 70,
        "damage" : 85,
        "damage_type" : "刺伤",
]),
([      "action" : "$N手中$w急递，一剑「怒见狂花」刺了出去,这是天羽奇剑中最无常，杀势威猛的一招，但见$w一层接一层地刺向$n,令$p躲闪不急",
        "skill_name" : "怒见狂花",
        "force" : 180,
        "dodge" : -15,
        "lvl" : 80,
        "damage" : 90,
        "damage_type" : "刺伤",

]),
([      "action" : "$N右手高举$w，大喝一声使出「顶天立地」自上而下斩向$n，其快绝无比，气势汹涌",
        "skill_name" : "顶天立地",
        "force" : 190,
        "dodge" : -20,
        "lvl" : 90,
        "damage" : 100,
        "damage_type" : "刺伤",

]),

([      "action" : "$N错步上前，使出「仰天长笑」，手中$w划出一道剑光劈向$n的$l",
        "skill_name" : "仰天长笑",
        "force" : 200,
        "dodge" : -20,
        "lvl" : 100,
        "damage" : 120,
        "damage_type" : "刺伤",

]),
});
string  *msg = ({

HIC"$N手中$w"HIC"剑气飞射，声若龙吟，悠悠不绝，一招「阴分阴晓」,分左右向$n袭来！"NOR,
HIC"上招未完，$N手中$w"HIC"的剑尖却已反刺,「仰天长笑」、「旭日出升」、「漫天飞雪」\n接连刺出，伴着呜呜声响,点向$n的$l"NOR,
HIC"$w"HIC"伴着剑气，在空中连续飞回，一式「长天一剑」已迅雷不急掩耳之试刺向$n，这正是\n“天羽二十四式”中的一剑"NOR,
HIC"突然“铛”的一声，龙吟大作，一道剑光如金虹般划破长空，好一式「怒屈金虹」，\n剑身自作曲伸，杀人于无形!"NOR,
HIC"$N不守反功，猛的划出一剑，一招「石破天惊」，就斩了出去。其招后发而先至，蓦\n然间已刺中了$n的$l"NOR,
HIC"只见$w"HIC"绕著$n，上下翻飞，$w"HIC"跳跃灵动，呜呜响声不绝，掀的阵阵狂风有如刀割，似\n要把$n从中劈开,好一招「弯弓射日」"NOR,
HIC"$N腕力已震，便已使出「九弧震日」，连运九道剑劲，一道道向$n排去"NOR,
HIC"$N身形反转，一剑「怒屈金虹」扑向$n,突然金虹半途折若惊电，变作「长虹贯日」\n，连人带剑，追射而出！"NOR,
HIC"杀气弥漫着整个空间，陡然「血踪万里」已经刺出，呼呼飞啸声中，$w"HIC"或直飞、或斜\n飞、或回旋、或下坠、或上升,霎时间$n的全部退路已被封死"NOR,
HIC"猛地里$w"HIC"向$n$l飞去，$N招式急变「怒见狂花」、「三潭印月」、「倒挂金钩」已然\n递出，在$p沉肩卸避之时，刺向$p的$l"NOR,
HIC"转眼间$w"HIC"飞舞刺到$n，$n却并不回头，听风辨器，一一挡开，但$w"HIC"便如长上了眼睛一\n般，竟然又旋刺中了$n的$l"NOR,
HIC"$N目不转睛的盯着$n，一招「咫尺天涯」就发了出去，看似平淡无奇，但其后招连绵\n，把$p的防守撕得支离破碎"NOR,
});

int valid_enable(string usage)
{
        return usage == "sword" || usage == "parry";
}
void skill_improved(object me)
{
   int skill=me->query_skill("tianyu-qijian", 1);
   if(skill >= 150 && !me->query("tianyu_1"))
   {
         me->set("tianyu_1", 1);   
         tell_object(me, HIW"\n\n忽然你灵光闪动，天羽奇剑每一招都在脑中重复着，顷刻间你领悟到
了天羽奇剑的精髓"+HIR+"剑随人意"+HIW+"，其二十四招剑决已经了然于胸,功力又
上升了一个新的境界！\n"NOR);
         me->add("int",1);
          
   }

}
int valid_learn(object me)
{

        if((int)me->query_int() <=25)
            return notify_fail("天羽奇剑最重要的是一个“悟”，你悟性不够不能学习\n");
        if((int)me->query("max_neili") < 100)
            return notify_fail("你的内力不够。\n");
        return 1;
}
string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{

        int i, level;
        string message;
        level   = (int)me->query_skill("tianyu-qijian",1);
        if( me->query("tianyu_1"))
        {             
             message = msg[random(sizeof(msg))];
             return ([
             "action":message,
             "damage":(random(5)+1)*100,
             "damage_type":"刺伤",
             "dodge": -10,
             "force":250+random(300)
            ]);

        }
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                return action[NewRandom(i, 20, level/5)];

}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        object weapon;
        weapon=me->query_temp("weapon");
        if (!objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("id") != "jinhong jian")
        return 0;
        if( damage_bonus < 100 )
        return 0;
        else
        {
                victim->receive_wound("qi", (damage_bonus - 100) / 2 );
                return HIY"只见一道金光划过，"+me->name()+"手中"HIR"金虹剑"HIY"上下翻飞，刹那间但见剑光，不见人影\n"NOR;
        }
        
}        

int practice_skill(object me)
{
       return notify_fail("天羽奇剑不能自行演练。\n");
}

string perform_action_file(string action)
{
    return __DIR__"tianyu-qijian/" + action;
}




