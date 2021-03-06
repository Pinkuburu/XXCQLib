// 可以饲养的宠物！NPC
// By 山猫Adx @ snow 99-12-12

#include <ansi.h>
#include <combat.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_SAVE;

string replace_color(string,int);
int set_zhi(string,string,int);
void create()
{
	seteuid(getuid());

	if (!restore()) {
		set_name("宠物", ({ "pet" }) );
		set("race", "野兽");
		set("age",1);
		set("owner","R");
		set("limbs", ({ "头部", "身体", "前心", "後背", "尾巴" }) );
		set("verbs", ({ "bite", "claw", "knock", "hoof" }) );
		set("combat_exp",100);
		set_skill("unarmed", 1);
		set_skill("parry", 1);
		set_skill("dodge", 1);
		set_skill("chongwu-quan", 1);
		set_skill("chongwu-tengnuo", 1);

		map_skill("unarmed" , "chongwu-quan");
		map_skill("parry" , "chongwu-quan");
		map_skill("dodge" , "chongwu-tengnuo");

		set_temp("apply/attack", 100);
		set_temp("apply/damage", 100);
		set_temp("apply/defence",100);
		set_temp("apply/armor", 100);
		setup();
	} else {
		set_name(query("name"), ({ query("id") }));
		setup();
	}
}

string query_save_file()
{
        string id;

        id = query("owner");
        if( !stringp(id) ) return 0;
        return sprintf(DATA_DIR "pet/%s", id);
}

int save()
{
        string file;

        if( stringp(file = this_object()->query_save_file()) ) {
                assure_file(file+ __SAVE_EXTENSION__);
                return save_object(file);
        }
        return 0;
}

int restore()
{
        string file;

        if( stringp(file = this_object()->query_save_file()) )
                return restore_object(file);
        return 0;
}

int heal_up()
{
        if(!objectp(this_object()->query("possessed")))
	{
	save();
	message_vision("$N一闪就不见了。\n",this_object());
        destruct(this_object());
	return 1;
	}
	add("mud_age",15);
	set_heart_beat(1);
        return ::heal_up();
}

void die()
{	
        int i, exp, qi, jingli;
        object owner, *enemy, pet, corpse;
	string skill;
	mapping skl;

//	set("deathstamp",time());
	pet=this_object();
	exp = (int) query("combat_exp");
	qi = (int) query("max_qi");
        jingli = (int) query("max_jingli");

	if(!environment()->query("no_death_penalty"))
	set("combat_exp",exp/10 * 9);
	set("eff_qi",qi);
	set("eff_jingli",jingli);
        set("qi",qi);
        set("jingli",jingli);
	skl=pet->query_skills();

	if(mapp(skl))
		foreach(skill in keys(skl))
	set_skill(skill,(pet->query_skill(skill,1)-1));
	save();
	if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
		corpse->move(environment());
	message_vision("$N死了！\n",pet);
	pet->move("/d/death/gate");
}

void init()
{
	if(this_player() == query("possessed")) {
	add_action("do_shezhi","shezhi");
	add_action("do_gongji","gongji");
	add_action("do_lianxi","lianxi");
	add_action("do_order","order");
	add_action("do_status","status");
	add_action("do_gen","gen");
	add_action("do_wei","wei");
	}
}

int do_order(string arg)
{
	int obedience;
	object me = this_player();
	obedience = query("obedience");
	if(random(100) < obedience )
	command( "emote " + arg);
	else
	command("en");
	return 1;
}

int do_wei(string arg)
{
	object pet =this_object();
	if( !arg ) return notify_fail("指令格式：wei <食物>|<水>|<water>。\n");

	if(arg=="水"||arg=="water") {
		if((pet->max_water_capacity()-pet->query("water"))<0)
			return notify_fail("可是你的宠物并不渴啊！\n");
		message_vision("$N对$n道：来喝口水。\n", this_player(), pet);
		if(!environment(pet)->query("resource/water") ) {
			add("xing",-10);
			message_vision("$N把头撇了过去，并不理睬$n。\n", pet, this_player());
			return 1;
		} else {
			add("xing",10);
			add("water",30);
			message_vision("$N低下头咕噜……咕噜……地喝了几口水。\n", pet);
			return 1;
		}
	}
	if(arg=="食物"||arg=="food") {
		if((pet->max_food_capacity()-pet->query("food"))<0)
			return notify_fail("可是你的宠物并不饿啊！\n");
		message_vision("$N对$n道：来吃啊！\n", this_player(), pet);
		if(!environment(pet)->query("resource/water") ) {
			add("xing",-10);
			message_vision("$N把头撇了过去，并不理睬$n。\n", pet, this_player());
			return 1;
		} else {
			add("xing",10);
			add("food",30);
			message_vision("$N低下头吧唧……吧唧……吃了起来。\n", pet);
			return 1;
		}
	}
	command("????");
	return 1;
}

int do_gen(string arg)
{
	object ob, pet;
	pet=this_object();
	if( !arg ) return notify_fail("指令格式：gen <某人>|none。\n");
        if((random(100)+200) > query("xing") ) {
		command("en");
		return 1; }
	if( arg=="none")
		if( pet->query_leader() ) {
			pet->set_leader(0);
			message_vision("$N开始单独行动。\n", pet);
			return 1;
		} else {
			write("你的宠物现在并没有跟随任何人。\n");
			return 1;
		}
	if( !objectp(ob = present(arg, environment(pet))) )
		return notify_fail("这里没有 " + arg + "。\n");

	add("xing",-1);
	pet->set_leader(ob);
	message_vision("$N决定开始跟随$n一起行动。\n", pet, ob);

	return 1;
}

int do_shezhi(string arg)
{
	string item, msg;
        object me = this_player();
	if(!arg || sscanf(arg,"%s %s",item,msg) != 2)
		return notify_fail("指令格式: shezhi <类型> <内容>\n");
	switch(item) {
	case "wimpy":
		set("env/wimpy", atoi(msg));
                write("ＯＫ\n");
		save();
		return 1;
	case "long":
		if( strlen(replace_color(msg,0)) > 100 )
			return notify_fail("描述太长啦！\n");
		msg +="\n";
		return set_zhi(msg,"long",1)?1:notify_fail("命令失败。\n");
		write("ＯＫ\n");
		save();
		return 1;
	case "nick" :
		if( strlen(replace_color(msg,0)) > 30 )
			return notify_fail("描述太长啦！\n");
		return set_zhi(msg,"nickname",1)?1:notify_fail("命令失败。\n");
		write("ＯＫ\n");
		save();
                return 1;
	case "title" :
		if( strlen(replace_color(msg,0)) > 30 )
			return notify_fail("描述太长啦！\n");
		return set_zhi(msg,"title",1)?1:notify_fail("命令失败。\n");
                write("ＯＫ\n");
		save();
                return 1;
	}
	return notify_fail("你要修改什么？\n");

}
int do_gongji(string arg)
{
	object me,obj;
	me = this_player();
        if( environment(me)->query("no_fight") )
                return notify_fail("这里不准战斗。\n");

        if( !arg )
                return notify_fail("你想杀谁？\n");

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("这里没有这个人。\n");

        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");
	message_vision(
	sprintf("$N偷偷指了指$n，然后看了%s一眼。\n",this_object()->name()),me,obj);
	add("shen",-10);
	add("xing",-10);
        if((random(100)+200) > query("xing") )
		command("en");
	else
		kill_ob(obj);
	return 1;
}

int do_lianxi(string arg)
{
	object me;
	string skill, kill;
	int i, j, itskill;
	me = this_player();

	switch(arg) {
	case "gongji": skill="chongwu-quan"; kill="战斗攻击力"; break;
	case "fangyu": skill="chongwu-tengnuo"; kill="战斗防御力"; break;
	default: return notify_fail("它学不会这项技能的！\n");
	}

	itskill = query_skill(skill,1);
	if(me->query("combat_exp") <= itskill*10000)
		return notify_fail(name()+"以嘲笑的目光望着你。\n");

	if((int)me->query("potential")-(int)me->query("learned_points") < 1)
		return notify_fail("你的潜能不够！\n");

	i = 100 / query("int");
	if((int)me->query("jingli") < i)
		return notify_fail("你还是休息一下再教吧！\n");

	if( query("jingli") < i)
		return notify_fail("你的宠物太累了！还是让他休息一下吧！\n");

	add("xing",-1);
	me->receive_damage("jingli",i);
	me->add("potential",-1);
	j = (me->query("int") * query("int")/20);
	tell_object(me,sprintf("你不厌其烦地教宠物「"+kill+"」。\n",));

        if((random(100)+200) > query("xing") ) {
		command("en");
		return 1;
	} else {
		receive_damage("jingli",i);
		add(arg,j);
		if(query(arg)>itskill*itskill) {

			delete(arg);
			set_skill(skill,(itskill+1));
	tell_object(me,sprintf(HIC"你的宠物还真的又学会了一级"+kill+"！\n"NOR,));
		}
	tell_object(me,sprintf("你的宠物还真的又学会了一些"+kill+"！\n",));
	}
	return 1;
}

int set_zhi(string str,string prop,int color_flag)
{
	object ob=this_object();
	if(prop=="title"||prop=="nickname"||prop=="long")
		if(str=="cancel")
		{
			ob->delete(prop);
			message_vision("$N的"+prop+"被清除了。\n",ob);
			return 1;
		}
	str=replace_color(str,color_flag);
	message_vision("$N的"+prop+"被设定为:"+str+"\n",ob);
	ob->set(prop,str);
	return 1;
}

string replace_color(string arg,int flag)
{
	arg = replace_string(arg, "$BLK$", flag?BLK:"");
	arg = replace_string(arg, "$RED$", flag?RED:"");
	arg = replace_string(arg, "$GRN$", flag?GRN:"");
	arg = replace_string(arg, "$YEL$", flag?YEL:"");
	arg = replace_string(arg, "$BLU$", flag?BLU:"");
	arg = replace_string(arg, "$MAG$", flag?MAG:"");
	arg = replace_string(arg, "$CYN$", flag?CYN:"");
	arg = replace_string(arg, "$WHT$", flag?WHT:"");
	arg = replace_string(arg, "$HIR$", flag?HIR:"");
	arg = replace_string(arg, "$HIG$", flag?HIG:"");
	arg = replace_string(arg, "$HIY$", flag?HIY:"");
	arg = replace_string(arg, "$HIB$", flag?HIB:"");
	arg = replace_string(arg, "$HIM$", flag?HIM:"");
	arg = replace_string(arg, "$HIC$", flag?HIC:"");
	arg = replace_string(arg, "$HIW$", flag?HIW:"");
	arg = replace_string(arg, "$NOR$", flag?NOR:"");
	arg = replace_string(arg, "$BLINK$", flag?BLINK:"");
	if(flag) arg+=NOR;
	return arg;
}

string status_color(int current, int max)
{
        int percent;

        if( max>0 ) percent = current * 100 / max;
        else percent = 100;
        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return RED;
}

int do_status(string arg)
{
	mapping my;
	object weapon;
	string shape, skill_type;
	int attack_points, dodge_points, parry_points;
	my = query_entire_dbase();

	if( objectp(weapon = this_object()->query_temp("weapon")) )
		skill_type = weapon->query("skill_type");
	else
		skill_type = "unarmed";

	attack_points = COMBAT_D->skill_power(this_object(), skill_type, SKILL_USAGE_ATTACK);
	parry_points = COMBAT_D->skill_power(this_object(), skill_type, SKILL_USAGE_DEFENSE);
	dodge_points = COMBAT_D->skill_power(this_object(), "dodge", SKILL_USAGE_DEFENSE);

	shape="这是一只"+my["name"]+"它";

	if(my["kill"]>=1000) shape+="非常凶恶而且";
	if(my["kill"]>=800 && my["kill"]<1000) shape+="凶恶而且";
	if(my["kill"]>=600 && my["kill"]<800) shape+="有些凶恶而且";
	if(my["kill"]>=500 && my["kill"]<600) shape+="有些温顺而且";
	if(my["kill"]>=300 && my["kill"]<500) shape+="温顺而且";
	if(my["kill"]<300 ) shape+="非常温顺而且";

	if(my["xing"]>=350) shape+="很听话";
	if(my["xing"]>=300 && my["xing"]<350) shape+="听话";
	if(my["xing"]>=250 && my["xing"]<300) shape+="有点听话";
	if(my["xing"]>=200 && my["xing"]<250) shape+="有点任性";
	if(my["xing"]>=150 && my["xing"]<200) shape+="任性";
	if(my["xing"]<150 ) shape+="很任性";

	printf(HIY"〖"+my["name"]+"状态表〗\n"NOR);
	printf(HIG"===============================================================\n"NOR);
	printf("精力：%s%3d/ %3d %s(%3d%%)"NOR"  气血：%s%3d/ %3d %s(%3d%%)"NOR"\n"+NOR,
                status_color(my["jingli"], my["eff_jingli"]), my["jingli"],my["eff_jingli"],
                status_color(my["eff_jingli"], my["max_jingli"]), my["eff_jingli"] * 100 / my["max_jingli"],
                status_color(my["qi"], my["eff_qi"]), my["qi"], my["eff_qi"],
                status_color(my["eff_qi"], my["max_qi"]), my["eff_qi"] * 100 / my["max_qi"],
	);		
	printf(HIC"主人："+HIM" %s\t\t"+HIC"经验： "+HIM"%d\t\t\n"NOR,
		my["owner"], my["combat_exp"],
	);
	printf(HIW"战斗攻击力 "HIM"%d (+%d)"HIW"\t\t战斗防御力 "HIM"%d (+%d)\n"NOR,
                attack_points/100 + 1,
                my["apply/damage"],
                (dodge_points + (parry_points/10))/100 + 1,
                my["apply/armor"]
        );
	printf(HIG"===============================================================\n"NOR);
	printf(WHT"  "+shape+"\n"NOR);
	printf(HIG"===============================================================\n"NOR);
	return 1;
}
/*
void unconcious()
{
die();
}
*/
