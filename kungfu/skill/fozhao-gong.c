// fozhao-gong.c 金刚佛爪功
// modified by Venus Oct.1997
inherit SKILL;

mapping *action = ({
([      "action" : "在呼呼风声中，$N使一招「伽蓝捕风」，双手如钩如戢，插向$n的$l",
    "force" : 100,
    "dodge" : 5,
    "lvl"   : 0,
    "skill_name" : "伽蓝捕风" ,
    "damage_type" : "内伤"
]),
([      "action" : "$N猛地向前跃出，一招「天龙捉影」，两腿踢出，双手抓向$n的面门",
    "force" : 110,
    "dodge" : 5,
    "damage": 5,
    "lvl"   : 6,
    "skill_name" : "天龙捉影" ,
    "damage_type" : "内伤"
]),
([      "action" : "$N双手平伸，十指微微上下抖动，一招「佛祖抚琴」打向$n的$l",    
    "force" : 120,
    "dodge" : 10,
    "damage": 5,
    "lvl"   : 12,
    "skill_name" : "佛祖抚琴" ,
    "damage_type" : "内伤"
]),
([      "action" : "$N左手上拦，右手内挥，一招「金刚击鼓」掌屈成爪击向$n胸口",
    "force" : 140,
    "dodge" : 10,
    "damage": 10,
    "lvl"   : 18,
    "skill_name" : "金刚击鼓" ,
    "damage_type" : "内伤"
]),
([      "action" : "$N右手虚握，左手掌立如山，一招「罗汉批亢」，猛地击向$n的$l",  
    "force" : 160,
    "dodge" : 15,
    "damage": 10,
    "lvl"   : 24,
    "skill_name" : "罗汉批亢" ,
    "damage_type" : "内伤"
]),
([      "action" : "$N腾步上前，左手护胸，右手探出，一招「功曹掏虚」击向$n的裆部",
    "force" : 190,
    "dodge" : 15,
    "damage": 15,
    "lvl"   : 30,
    "skill_name" : "功曹掏虚" ,
    "damage_type" : "内伤"
]),
([      "action" : "$N双手平提胸前，左手护住面门，一招「揭谛抱残」右手推向$n的$l",
    "force" : 220,
    "dodge" : 20,
    "damage": 15,
    "lvl"   : 35,
    "skill_name" : "揭谛抱残" ,
    "damage_type" : "内伤"
]),
([      "action" : "$N两手胸前环抱，腋下含空，五指如钩，一招「丁甲守缺」插向$n的顶门",
    "force" : 260,
    "dodge" : 20,
    "damage": 20,
    "lvl"   : 40,
    "skill_name" : "丁甲守缺" ,
    "damage_type" : "内伤"
]),
([      "action" : "$N右腿斜插$n二腿之间，一招「比丘抢珠」，上手取目，下手反勾$n的裆部",
    "force" : 300,
    "dodge" : 25,
    "damage": 20,
    "lvl"   : 45,
    "skill_name" : "比丘抢珠" ,
    "damage_type" : "内伤"
]),
([      "action" : "$N一手虚指$n的剑诀，一招「菩萨夺剑」，一手劈空抓向$n手中的兵器",
    "force" : 350,
    "dodge" : 25,
    "damage": 25,
    "lvl"   : 50,
    "skill_name" : "菩萨夺剑" ,
    "damage_type" : "内伤"
]),
([      "action" : "$N左手指向$n胸前的五道大穴，右手斜指太阳穴，一招「尊者拿云」使$n进退两难",
    "force" : 400,
    "dodge" : 30,
    "damage": 25,
    "lvl"   : 55,
    "skill_name" : "尊者拿云" ,
    "damage_type" : "内伤"
]),
([      "action" : "$N前脚着地，一手顶天成爪，一手指地，一招「金乌追日」劲气笼罩$n的全身",
    "force" : 460,
    "dodge" : 40,
    "damage": 30,
    "lvl"   : 60,
    "skill_name" : "金乌追日" ,
    "damage_type" : "内伤"
])
});

int valid_enable(string usage) { return usage=="claw" ||  usage=="parry"; }     

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
   return notify_fail("练金刚佛爪功必须空手。\n");
    if ((int)me->query_skill("banruo-changong", 1) < 20)
   return notify_fail("你的内功火候不够，无法学金刚佛爪功。\n");
    if ((int)me->query("max_neili") < 100)
   return notify_fail("你的内力太弱，无法练金刚佛爪功。\n");
    return 1;
}

string query_skill_name(int level)
{
    int i;
    for(i = sizeof(action); i > 0; i--)
   if(level >= action[i-1]["lvl"])
      return action[i-1]["skill_name"];
}

mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int) me->query_skill("fozhao-gong",1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
      return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
    if ((int)me->query("qi") < 30)
       return notify_fail("你的体力太低了。\n");
    if ((int)me->query("neili") < 20)
       return notify_fail("你的内力不够练金刚佛爪功。\n");
    me->receive_damage("qi", 30);
    me->add("neili", -10);
    return 1;
}

