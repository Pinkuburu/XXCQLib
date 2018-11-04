// human.c
// From ES2
// Modified by Load@SNOW

#define BASE_WEIGHT 40000

inherit F_DBASE;
inherit F_SKILL;

mapping *combat_action = ({
	([	"action":	"$N��ȭ����$n��$l",
		"damage_type":	"����",
	]),
	([	"action":	"$N��$n��$lһץ",
		"damage_type":	"ץ��",
	]),
	([	"action":	"$N��$n��$l�ݺݵ�����һ��",
		"damage_type":	"����",
	]),
	([	"action":	"$N����ȭͷ��$n��$l��ȥ",
		"damage_type":	"����",
	]),
	([	"action":	"$N��׼$n��$l�����ӳ�һȭ",
		"damage_type":	"����",
	]),
});

void create()
{
	seteuid(getuid());
	set("unit", "λ");
	set("gender", "����");
	set("can_speak", 1);
	set("attitude", "peaceful");
	set("limbs", ({
		"ͷ��",	"����",	"�ؿ�",	"����",	"���",	"�Ҽ�",	"���",
		"�ұ�",	"����",	"����",	"����",	"С��",	"����",	"����",
		"���",	"�ҽ�"
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

	// �������(��δ����ɱ����NPC)��ɱ��
	if( undefinedp(my["kill"]) )
	{
		if (userp(ob))	my["kill"] = 0;
		else my["kill"] = (my["combat_exp"] * my["bac"])/ 50;
	}

	// �������(��δ�������NPC)����
	if( undefinedp(my["shen"]) )
	{
		if (userp(ob)) my["shen"] = 0;
		else my["shen"] = my["shen_type"] * my["combat_exp"] / 10;
	}

	// �������(��δ������Ч��־��NPC)��Ч��־
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

	// ����������\�����Ƿ񳬹��������ֵ
	if (userp(ob))
	{
		if (my["max_neili"] > (int)ob->query_skill("force") * my["con"] + 1)
			my["max_neili"] = (int)ob->query_skill("force",1) * my["con"] + 1;
		if (my["max_jingli"] > ((int)ob->query_skill("force",1) * my["con"] * 7 / 9 + 100))
			my["max_jingli"] = ((int)ob->query_skill("force",1) * my["con"] * 7 / 9) + 100;
	}

	// �������(��δ�������ǵ�NPC)������
	if (undefinedp(my["max_shenzhi"]) || userp(ob))
	{
		my["max_shenzhi"] = my["bac"]*10;
		my["max_shenzhi"] += (my["max_neili"]/20);
	}

	// �������ÿ����һ�����ӵľ���
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

	// ����(���)����(��δ���������Ϣ��NPC)�������Ϣ
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