// 针灸盒 药王庄医疗施毒的道具。
// By 山猫Adx 16:53 99-10-25

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name( CYN "针灸盒" NOR , ({"zhenjiu he", "zhenjiu", "box"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", CYN"这是一个针灸盒，是药王谷弟子医疗和施毒的工具。\n"
				"	xiadu	下毒\n"
				"	heal	疗伤\n"
				"	jiedu	解毒\n"NOR);
		set("unit", "个");
		set("nopwan", 1);
		set("no_sell", 1);
		set("no_drop", 1);
		set("no_give", 1);
		set("value", 0);
		set("weight", 100);
	}
}

void init()
{
	add_action("do_xiadu", "xiadu"); //下毒
	add_action("do_heal", "heal"); //疗伤
	add_action("do_jiedu", "jiedu"); //解毒
}

int do_heal(string arg)
{
	object me, ob;
	int i;
	me=this_player();
	i=( 100 - (int)me->query_skill("healing",1) );

	if(me->query("party/party_name")!=HIB"药王谷"NOR
		|| me->query("party/level")<5 )
		return notify_fail("你不能使用这个针灸盒！\n");

	if( me->query("shen")<0 )
		return notify_fail("你不会使用着项技能！\n");

	if( !arg )
		return notify_fail("指令格式：heal <ID> \n");

	if(!objectp(ob = present(arg, environment(me))))
		return notify_fail("这里没有这个人！\n");

        if( me->is_fighting() || me->is_busy() )
                return notify_fail("你正忙着呢！\n");

        if( ob->is_fighting() || ob->is_busy() )
                return notify_fail("他正忙着呢！\n");

	if( me->query("shen")<0 )
		return notify_fail("你不会使用着项技能！\n");

	if( i<5 ) i=5;
	if( i>80 ) i=80;
	if(me->query("jingli")<=i)
		return notify_fail("你太累了，先休息一下吧！\n");

	if( ob->query("max_qi")>=(ob->query("eff_qi")+(i*2)) ) {
		ob->set("max_qi",(ob->query("eff_qi")+(i*2)));
	} else { ob->set("eff_qi",(ob->query("max_qi"))); }

	message_vision(CYN"$N从针灸盒中拿出一根银针在$n穴位上扎了几下。\n"NOR, me, ob);
	message_vision(WHT"$N吐出一口淤血，脸色看起来好多了。\n"NOR, ob);
	me->improve_skill("healing", ((int)me->query_skill("healing",1)/3));
	me->add("jingli", -i);
	me->start_busy(3);
	return 1;
}

int do_xiadu(string arg)
{
	object me, ob;
	int i;
	me=this_player();
	i=( 100 - (int)me->query_skill("healing",1) );

	if(me->query("party/party_name")!=HIB"药王谷"NOR
		|| me->query("party/level")<5 )
		return notify_fail("你不能使用这个针灸盒！\n");

	if( me->query("shen")>0 )
		return notify_fail("你不会使用着项技能！\n");

	if( (environment(me))->query("no_fight") )
		return notify_fail("这里禁止战斗！\n");

	if( !arg )
		return notify_fail("指令格式：xiadu <ID> \n");

	if(!objectp(ob = present(arg, environment(me))))
		return notify_fail("这里没有这个人！\n");

        if( me->is_fighting() || me->is_busy() )
                return notify_fail("你正忙着呢！\n");

	if( i<5 ) i=5;
	if( i>80 ) i=80;
	if(me->query("jingli")<=i)
		return notify_fail("你太累了，先休息一下吧！\n");

	message_vision(HIR"$N轻轻按了一下针灸盒。突然从盒中射出几支"
		HIW"银针"HIR"尽数打在$n身上。\n"NOR, me, ob);
	ob->receive_damage("qi",(int)me->query_skill("healing",1));
		if(random(10)<5) {
	ob->apply_condition("yao1_poison", ((int)me->query_condition("yao1_poison")+i));
		} else {
	ob->apply_condition("yao1_poison", ((int)me->query_condition("yao2_poison")+(i*10)));
		}
	ob->improve_skill("healing", ((int)me->query_skill("healing",1)/3));
	me->add("jingli", -i);
	me->start_busy(3);
		if(random(me->query_skill("healing",1))<50) {
			ob->kill_ob(me); }
	return 1;
}

int do_jiedu(string arg)
{
	object me, ob;
	int i;
	me=this_player();
	i=( 100 - (int)me->query_skill("healing",1) );

	if(me->query("party/party_name")!=HIB"药王谷"NOR
		|| me->query("party/level")<5 )
		return notify_fail("你不能使用这个针灸盒！\n");

	if( me->query("shen")>0 )
		return notify_fail("你不会使用着项技能！\n");

	if( !arg )
		return notify_fail("指令格式：jiedu <ID> \n");

	if(!objectp(ob = present(arg, environment(me))))
		return notify_fail("这里没有这个人！\n");

        if( me->is_fighting() || me->is_busy() )
                return notify_fail("你正忙着呢！\n");

        if( ob->is_fighting() || ob->is_busy() )
                return notify_fail("他正忙着呢！\n");

	if( i<5 ) i=5;
	if( i>80 ) i=80;
	if(me->query("jingli")<=i)
		return notify_fail("你太累了，先休息一下吧！\n");

	message_vision(CYN"$N从针灸盒中拿出一根银针在$n穴位上扎了几下。\n"NOR, me, ob);

//解 五毒之气
	if( (int)me->query_condition("yao1_poison")>=1 ) {
		if ((int)me->query_condition("yao1_poison") <= 10 ) {
			me->apply_condition("yao1_poison", 0);
	message_vision(YEL"$N身上的"HIB"五毒之气"NOR+YEL"尽退，脸色看上去好多了。\n"NOR, me); 
	} else {
	message_vision(YEL"$N身上的"HIB"五毒之气"NOR+YEL"清去一些脸色渐渐红润起来。\n"NOR, me);
	me->apply_condition("yao1_poison", (int)me->query_condition("yao1_poison") -10);
        }
	me->improve_skill("healing", ((int)me->query_skill("healing",1)/3));
		me->add("jingli", -i);
		me->start_busy(3);
		return 1;
	}

//解 小五毒之气
	if( (int)me->query_condition("yao2_poison")>=1 ) {
		if ((int)me->query_condition("yao2_poison") <= 10 ) {
			me->apply_condition("yao2_poison", 0);
	message_vision(YEL"$N身上的"HIB"小五毒之气"NOR+YEL"尽退，脸色看上去好多了。\n"NOR, me); 
	} else {
	message_vision(YEL"$N身上的"HIB"小五毒之气"NOR+YEL"清去一些脸色渐渐红润起来。\n"NOR, me);
	me->apply_condition("yao2_poison", (int)me->query_condition("yao2_poison") -10);
        }
	me->improve_skill("healing", ((int)me->query_skill("healing",1)/3));
		me->add("jingli", -i);
		me->start_busy(3);
		return 1;
	}

//解 飞行之毒
	if( (int)me->query_condition("feixing_poison")>=1 ) {
		if ((int)me->query_condition("feixing_poison") <= 10 ) {
			me->apply_condition("feixing_poison", 0);
	message_vision(YEL"$N身上的"HIB"飞行之毒"NOR+YEL"尽退，脸色看上去好多了。\n"NOR, me); 
	} else {
	message_vision(YEL"$N身上的"HIB"飞行之毒"NOR+YEL"清去一些脸色渐渐红润起来。\n"NOR, me);
	me->apply_condition("feixing_poison", (int)me->query_condition("feixing_poison") -10);
        }
	me->improve_skill("healing", ((int)me->query_skill("healing",1)/3));
		me->add("jingli", -i);
		me->start_busy(3);
		return 1;
	}

//解 幽冥飞针之毒
	if( (int)me->query_condition("hx_poison")>=1 ) {
		if ((int)me->query_condition("hx_poison") <= 10 ) {
			me->apply_condition("hx_poison", 0);
	message_vision(YEL"$N身上的"HIB"幽冥飞针之毒"NOR+YEL"尽退，脸色看上去好多了。\n"NOR, me); 
	} else {
	message_vision(YEL"$N身上的"HIB"幽冥飞针之毒"NOR+YEL"清去一些脸色渐渐红润起来。\n"NOR, me);
	me->apply_condition("hx_poison", (int)me->query_condition("hx_poison") -10);
        }
		me->improve_skill("healing", (i/3));
		me->add("jingli", -i);
		me->start_busy(3);
		return 1;
	}

//解 声毒
	if( (int)me->query_condition("shengdu_poison")>=1 ) {
		if ((int)me->query_condition("shengdu_poison") <= 10 ) {
			me->apply_condition("shengdu_poison", 0);
	message_vision(YEL"$N身上的"HIB"声毒"NOR+YEL"尽退，脸色看上去好多了。\n"NOR, me); 
	} else {
	message_vision(YEL"$N身上的"HIB"声毒"NOR+YEL"清去一些脸色渐渐红润起来。\n"NOR, me);
	me->apply_condition("shengdu_poison", (int)me->query_condition("shengdu_poison") -10);
        }
	me->improve_skill("healing", ((int)me->query_skill("healing",1)/3));
		me->add("jingli", -i);
		me->start_busy(3);
		return 1;
	}

//解 蛇毒
	if( (int)me->query_condition("snake_poison")>=1 ) {
		if ((int)me->query_condition("snake_poison") <= 10 ) {
			me->apply_condition("snake_poison", 0);
	message_vision(YEL"$N身上的"HIB"蛇毒"NOR+YEL"尽退，脸色看上去好多了。\n"NOR, me); 
	} else {
	message_vision(YEL"$N身上的"HIB"蛇毒"NOR+YEL"清去一些脸色渐渐红润起来。\n"NOR, me);
	me->apply_condition("snake_poison", (int)me->query_condition("snake_poison") -10);
        }
	me->improve_skill("healing", ((int)me->query_skill("healing",1)/3));
		me->add("jingli", -i);
		me->start_busy(3);
		return 1;
	}

//解 相识蜂雨中
	if( (int)me->query_condition("xiangshi_poison")>=1 ) {
		if ((int)me->query_condition("xiangshi_poison") <= 10 ) {
			me->apply_condition("xiangshi_poison", 0);
	message_vision(YEL"$N身上的"HIB"相识蜂雨中之毒"NOR+YEL"尽退，脸色看上去好多了。\n"NOR, me); 
	} else {
	message_vision(YEL"$N身上的"HIB"相识蜂雨中之毒"NOR+YEL"清去一些脸色渐渐红润起来。\n"NOR, me);
	me->apply_condition("xiangshi_poison", (int)me->query_condition("xiangshi_poison") -10);
        }
	me->improve_skill("healing", ((int)me->query_skill("healing",1)/3));
		me->add("jingli", -i);
		me->start_busy(3);
		return 1;
	}

//解 蝎毒
	if( (int)me->query_condition("xie_poison")>=1 ) {
		if ((int)me->query_condition("xie_poison") <= 10 ) {
			me->apply_condition("xie_poison", 0);
	message_vision(YEL"$N身上的"HIB"蝎毒"NOR+YEL"尽退，脸色看上去好多了。\n"NOR, me); 
	} else {
	message_vision(YEL"$N身上的"HIB"蝎毒"NOR+YEL"清去一些脸色渐渐红润起来。\n"NOR, me);
	me->apply_condition("xie_poison", (int)me->query_condition("xie_poison") -10);
        }
	me->improve_skill("healing", ((int)me->query_skill("healing",1)/3));
		me->add("jingli", -i);
		me->start_busy(3);
		return 1;
	}

//解 吸髓之毒
	if( (int)me->query_condition("xisui_poison")>=1 ) {
		if ((int)me->query_condition("xisui_poison") <= 10 ) {
			me->apply_condition("xisui_poison", 0);
	message_vision(YEL"$N身上的"HIB"吸髓之毒"NOR+YEL"尽退，脸色看上去好多了。\n"NOR, me); 
	} else {
	message_vision(YEL"$N身上的"HIB"吸髓之毒"NOR+YEL"清去一些脸色渐渐红润起来。\n"NOR, me);
	me->apply_condition("xisui_poison", (int)me->query_condition("xisui_poison") -10);
        }
	me->improve_skill("healing", ((int)me->query_skill("healing",1)/3));
		me->add("jingli", -i);
		me->start_busy(3);
		return 1;
	}

//解 恙毒
	if( (int)me->query_condition("yangdu_poison")>=1 ) {
		if ((int)me->query_condition("yangdu_poison") <= 10 ) {
			me->apply_condition("yangdu_poison", 0);
	message_vision(YEL"$N身上的"HIB"恙毒"NOR+YEL"尽退，脸色看上去好多了。\n"NOR, me); 
	} else {
	message_vision(YEL"$N身上的"HIB"恙毒"NOR+YEL"清去一些脸色渐渐红润起来。\n"NOR, me);
	me->apply_condition("yangdu_poison", (int)me->query_condition("yangdu_poison") -10);
        }
	me->improve_skill("healing", ((int)me->query_skill("healing",1)/3));
		me->add("jingli", -i);
		me->start_busy(3);
		return 1;
	}
	else {
		message_vision(CYN"可是$N并没有中毒啊！\n"NOR, ob);
		me->add("jingli", -i);
		me->start_busy(3);
		return 1;
	}
}
