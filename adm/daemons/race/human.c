// human.c
// From ES2
// Modified by Load@SNOW

#define BASE_WEIGHT 40000

inherit F_DBASE;
inherit F_SKILL;

mapping *combat_action = ({
	([	"action":	"$N挥拳攻击$n的$l",
		"damage_type":	"瘀伤",
	]),
	([	"action":	"$N往$n的$l一抓",
		"damage_type":	"抓伤",
	]),
	([	"action":	"$N往$n的$l狠狠地踢了一脚",
		"damage_type":	"瘀伤",
	]),
	([	"action":	"$N提起拳头往$n的$l捶去",
		"damage_type":	"瘀伤",
	]),
	([	"action":	"$N对准$n的$l用力挥出一拳",
		"damage_type":	"瘀伤",
	]),
});

void create()
{
	seteuid(getuid());
	set("unit", "位");
	set("gender", "男性");
	set("can_speak", 1);
	set("attitude", "peaceful");
	set("limbs", ({
		"头部",	"颈部",	"胸口",	"后心",	"左肩",	"右肩",	"左臂",
		"右臂",	"左手",	"右手",	"腰间",	"小腹",	"左腿",	"右腿",
		"左脚",	"右脚"
	}) );
}

void setup_human(object ob)
{
	mapping my;

	my = ob->query_entire_dbase();

	ob->set("default_actions", (: call_other, __FILE__, "query_action" :));
	
	if (undefinedp(my["age"])) my["age"] = 14;
	if (undefinedp(my["str"])) my["str"] = 10 + random(21);
	if (undefinedp(my["con"])) my["con"] = 10 + random(21);
	if (undefinedp(my["dex"])) my["dex"] = 10 + random(21);
	if (undefinedp(my["int"])) my["int"] = 10 + random(21);
	if (undefinedp(my["per"])) my["per"] = 10 + random(21);
	if (undefinedp(my["kar"])) my["kar"] = 10 + random(21);
	if (undefinedp(my["bac"])) my["bac"] = 10 + random(21);
	if (undefinedp(my["apt"])) my["apt"] = 20 + random(30);
	if (undefinedp(my["max_neili"])) my["max_neili"] = 1;
	if (undefinedp(my["max_jingli"])) my["max_jingli"] = 100;

	// 定义玩家(或未定义杀气的NPC)的杀气
	if( undefinedp(my["kill"]) )
	{
		if (userp(ob))	my["kill"] = 0;
		else my["kill"] = (my["combat_exp"] * my["bac"])/ 50;
	}

	// 定义玩家(或未定义神的NPC)的神
	if( undefinedp(my["shen"]) )
	{
		if (userp(ob)) my["shen"] = 0;
		else my["shen"] = my["shen_type"] * my["combat_exp"] / 10;
	}

	// 定义玩家(或未定义有效斗志的NPC)有效斗志
	if( userp(ob) || undefinedp(my["eff_douzhi"]) )
	{
		my["eff_douzhi"] = 100;
		if ((int)ob->query_skill("confu", 1)){
			my["eff_douzhi"] += (int)ob->query_skill("confu", 1)/4;
			my["eff_douzhi"] += my["kill"]/5000;}
		if ((int)ob->query_skill("buddha", 1)){
			my["eff_douzhi"] += (int)ob->query_skill("buddha", 1)/4;
			my["eff_douzhi"] += my["kill"]/4500;}
		if ((int)ob->query_skill("tao", 1)){
			my["eff_douzhi"] += (int)ob->query_skill("tao", 1)/4;
			my["eff_douzhi"] += my["kill"]/5500;}
	}

	// 检测玩家内力\精力是否超过允许最大值
	if (userp(ob))
	{
		if (my["max_neili"] > (int)ob->query_skill("force") * my["con"] + 1)
			my["max_neili"] = (int)ob->query_skill("force",1) * my["con"] + 1;
		if (my["max_jingli"] > ((int)ob->query_skill("force",1) * my["con"] * 7 / 9 + 100))
			my["max_jingli"] = ((int)ob->query_skill("force",1) * my["con"] * 7 / 9) + 100;
	}

	// 定义玩家(或未定义神智的NPC)的神智
	if (undefinedp(my["max_shenzhi"]) || userp(ob))
	{
		my["max_shenzhi"] = my["bac"]*10;
		my["max_shenzhi"] += (my["max_neili"]/20);
	}

	// 定义玩家每增加一岁增加的精力
	if (userp(ob))
	{
		if (my["age"] >= 15 && my["age"] <= 30 && ob->query("addjingli") < (my["age"]-14))
		{
			if ((int)ob->query_skill("confu", 1))
				my["max_jingli"] += my["con"] * 2;
			else if ((int)ob->query_skill("buddha", 1))
				my["max_jingli"] += my["con"] * 1.7;
			else if ((int)ob->query_skill("tao", 1))
				my["max_jingli"] += my["con"] * 1.3;
			else my["max_jingli"] += my["con"];
			ob->add("addjingli", 1);
		}
	}

	// 定义(检测)人类(或未定义最大气息的NPC)的最大气息
	if( userp(ob) || undefinedp(my["max_qi"]) ) {
		my["max_qi"] = 100;
		if( my["age"] <= 30 ) my["max_qi"] = 100 + (my["age"] - 14) * my["con"];
		else my["max_qi"] = my["con"] * 16 + 100;

		if ((int)ob->query_skill("confu", 1)){
			my["max_qi"] += (my["max_qi"]*(ob->query_skill("confu", 1)/2))/10;}
		if ((int)ob->query_skill("buddha", 1)){
			my["max_qi"] += (my["max_qi"]*(ob->query_skill("buddha", 1)/2.4))/10;}
		if ((int)ob->query_skill("tao", 1)){
			my["max_qi"] += (my["max_qi"]*(ob->query_skill("tao", 1)/1.5))/10;}
		
		if( my["max_neili"] > 0 ) my["max_qi"] += my["max_neili"] / 4;
	}

	ob->set_default_object(__FILE__);
	if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["str"] - 10)* 2000);
}

mapping query_action()
{
	return combat_action[random(sizeof(combat_action))];
}
