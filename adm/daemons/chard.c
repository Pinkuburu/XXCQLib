// chard.c
// From ES2
// Modified by Xiang@XKX

#define HUMAN_RACE "/adm/daemons/race/human"
#define BEAST_RACE "/adm/daemons/race/beast"
#define MONSTER_RACE "/adm/daemons/race/monster"

void create() { seteuid(getuid()); }

void setup_char(object ob)
{
	string race;
	mapping my;
	if( !stringp(race = ob->query("race")) )
	{
		race = "人类";
		ob->set("race", "人类");
	}
	switch(race)
	{
		case "人类":
			HUMAN_RACE->setup_human(ob);
			break;
		case "妖魔":
			MONSTER_RACE->setup_monster(ob);
			break;
		case "野兽":
			BEAST_RACE->setup_beast(ob);
			break;
		default:
			ob->set("race","人类");
			CHANNEL_D->do_channel(ob,"debug",ob->name(1)+"的种族类别错误，已经被缺省设置为人类。");
			error("Chard: undefined race " + race + ".\n");
	}
	my = ob->query_entire_dbase();
	//以后增加对潜能的限制！
	if (undefinedp(my["neili"])) my["neili"] = 1;
	if (undefinedp(my["douzhi"])) my["douzhi"] = my["eff_douzhi"];
	if (undefinedp(my["max_douzhi"])) my["max_douzhi"] = my["eff_douzhi"]*2;
	if (undefinedp(my["jingli"])) my["jingli"] = my["max_jingli"];
	if (undefinedp(my["eff_jingli"]) || my["eff_jingli"] > my["max_jingli"]) my["eff_jingli"] = my["max_jingli"];
	if (undefinedp(my["qi"])) my["qi"] = my["max_qi"];
	if (undefinedp(my["eff_qi"]) || my["eff_qi"] > my["max_qi"]) my["eff_qi"] = my["max_qi"];
	if (undefinedp(my["shen_type"]) ) my["shen_type"] = 0;
	if (undefinedp(my["shenzhi"])) my["shenzhi"] = my["max_shenzhi"];
	if (my["max_douzhi"]!=my["eff_douzhi"]*2) my["max_douzhi"]=my["eff_douzhi"]*2;
	if (my["douzhi"] > my["max_douzhi"]) my["douzhi"] = my["max_douzhi"];
	if (my["shenzhi"] > my["max_shenzhi"]) my["shenzhi"] = my["max_shenzhi"];
	// avoid excess neili
	if (userp(ob) && (int)ob->query_skill("force") > (int)ob->query_skill("force", 1)) 
	{
	if (my["max_neili"]>(int)ob->query_skill("force",1)*(int)ob->query("con")) 
			my["max_neili"]=((int)ob->query_skill("force",1)*(int)ob->query("con"));
		if (my["neili"] > my["max_neili"])
			my["neili"] = my["max_neili"];
	}
	if( !ob->query_max_encumbrance() )
		ob->set_max_encumbrance( ob->query_str() * 5000 );
	ob->reset_action();
}

varargs object make_corpse(object victim, object killer)
{
	int i;
	object corpse, *inv;

	if( victim->is_ghost() )
	{
		inv = all_inventory(victim);
		inv->owner_is_killed(killer);
		inv -= ({ 0 });
		i = sizeof(inv);
		while(i--) inv[i]->move(environment(victim));
		return 0;
	}

	corpse = new(CORPSE_OB);
	corpse->set_name( victim->name(1) + "的尸体", ({ "corpse" }) );
	corpse->set("long", victim->long()
		+ "然而，" + gender_pronoun(victim->query("gender")) 
		+ "已经死了，只剩下一具尸体静静地躺在这里。\n");
	corpse->set("age", victim->query("age"));
	corpse->set("gender", victim->query("gender"));
	corpse->set("victim_name", victim->name(1));
	corpse->set_weight( victim->query_weight() );
	corpse->set_max_encumbrance( victim->query_max_encumbrance() );
	corpse->move(environment(victim));
	
	// Don't let wizard left illegal items in their corpses.
	if( !wizardp(victim) &&!victim->is_dealer()) {
		inv = all_inventory(victim);
		inv->owner_is_killed(killer);
		inv -= ({ 0 });
		i = sizeof(inv);
		while(i--) {
			if( (string)inv[i]->query("equipped")=="worn" ) {
				inv[i]->move(corpse);
				if( !inv[i]->wear() ) inv[i]->move(environment(victim));
			}
			else inv[i]->move(corpse);
		}
	}

	return corpse;
}

varargs object make_wutoucorpse(object corpse)
{
	string name,oldname;
	sscanf(corpse->query("name"),"%s的尸体%*s",oldname);
	corpse->set("oldname",oldname);
	switch(corpse->query("gender"))
	{
	case "男性":
		name="无头男尸";
		break;
	case "女性":
		name="无头女尸";
		break;
	default:
		name="性别不明的尸体";
		break;
	}

	corpse->set("name",name);
	corpse->set("id",({"wutou corpse"}));
	return corpse;
}

varargs object make_toulu(object corpse)
{
	object toulu;
	toulu=new("/clone/misc/toulu");
	toulu->set("name",(string)corpse->query("oldname")+"的头颅");
	toulu->set("gender",corpse->query("gender"));
	toulu->set("age",corpse->query("age"));
	return toulu;
}
