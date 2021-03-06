// liangong-fu.c

inherit ITEM;
#include <ansi.h>
int do_shouzhang();
int consider_lv(object ob,int a);

void create()
{
	set_name("欠单", ({ "dan"}));
	set("long", "待定。\n");
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "paper");
		set("value", 60);
		set("unit", "张");
	}
	setup();
}

void init()
{
	add_action("do_shouzhang","shouzhang");
}

int do_shouzhang()
{
    object ob, me;
	string arg;

	me = this_player();
	arg = me->query_temp("subject");

	if (me->query_temp("qljob")!=1)
		return notify_fail("你不能用这张账单去收帐。\n");

	if( !objectp(ob = present(arg, environment(me))) )
		return notify_fail("你要讨债的人不在这里。\n");

	message_vision(HIW"\n$N从袖中掏出一张欠单，猛地一抖，大声喝道：“"+ob->query("name")+
		"，你欠我们钱庄的"+chinese_number(me->query_temp("money"))+
		"两银子也该还了吧？”\n"NOR,me);
	me->set_temp("qljob",2);
	me->apply_condition("jyfail",30);
	call_out("qljob_1", 3, me, ob);
	return 1;
}

int qljob_1(object me,object ob)
{
	object to_ob;

	to_ob = present("silver_money", me);

	if (environment(me)==environment(ob))
	{
		if (random(100) > 75)
		{
			message_vision("\n" + HIW + ob->query("name")+"被吓得打了一个哆嗦，忙不迭声的道：“还！还！还！”\n"NOR,me);
			message_vision("\n" + HIW + ob->query("name")+"急急忙忙从衣襟下掏出一个小钱袋，拿出了一些碎银子给了$N\n"NOR,me);
			if( !to_ob ) {
				to_ob = new("/clone/money/silver");
				to_ob->move(this_player());
				to_ob->set_amount(me->query_temp("money"));
			} else
				to_ob->add_amount(me->query_temp("money"));
			message_vision("\n" + HIW + "$N点了点头道：“这样做好，你我都好办事。”，说完将欠账单撕掉了。\n\n"NOR, me);
			me->set_temp("qljob",3);
			me->apply_condition("jyfail",0);
			destruct(this_object());
			return 1;
		}
		else
		{
			message_vision("\n" + HIW + ob->query("name")+"面露难色，小心翼翼陪着笑脸道：“我最近手里没钱，您看能不能宽限几天？”\n"NOR, me);
			message_vision("\n" + HIW + "$N皱了皱眉头：“什么！没钱！？”\n"NOR, me);
			write(HIR"\n是否杀掉"+ob->query("name")+"(杀(Y)，不杀(N))："NOR);
			me->set_temp("block_msg/all");
			input_to("qljob_2", me, ob);
			return 1;
		}
	}

	write("看来你收帐的对象溜掉了，钱是收不到了。\n");
	return 1;
}

void qljob_2(string sel,object me,object ob)
{
	me->delete_temp("block_msg/all");

	if (sel=="Y"||sel=="y")
	{
		message_vision("\n" + HIY + "$N拍案而起，目露凶光怒道：“没钱？我看你是成心捣乱，真是找死！”\n\n"NOR ,me);
		me->kill_ob(ob);
		ob->kill_ob(me);
		call_out("qljob_3",4+random(4),me);
		return;
	}
	else if(sel=="N"||sel=="n")
	{
		message_vision("\n" + HIG + "$N叹了口气道：“算了，这笔帐我帮你还上吧。”，说罢把欠账单撕了粉碎。\n"NOR,me);
		message_vision("\n" + HIG + "$n感激得简直不知道该说些什么了。"NOR,me,ob);
		me->set_temp("qljob",5);
		destruct(this_object());
		return;
	}
	else{
		write(HIR"请选择N or Y："NOR);
		input_to("qljob_2", me, ob);
	}
	return;
}

void qljob_3(object me)
{
    object ob,tar;

      tar = new("/d/xiangyang/npc/"+this_player()->query_temp("subject"));
      tar->move(environment(this_player()));
          me->start_busy(3);

	ob = new("/d/quanli/npc/xiashi");
	ob->set("combat_exp",me->query("combat_exp") * 4 / 5);
	ob->set("max_qi",me->query("max_qi"));
	ob->set("eff_qi",me->query("max_qi"));
	ob->set("qi",me->query("max_qi"));
	ob->set("max_jingli",me->query("max_jingli"));
	ob->set("eff_jingli",me->query("max_jingli"));
	ob->set("jingli",me->query("max_jingli"));
	ob->set("max_neili",me->query("max_neili"));
	ob->set("neili",me->query("max_neili"));
	ob->set_skill("force", consider_lv(ob, 7));
	ob->set_skill("jiuqu-xinfa", consider_lv(ob, 7));
	ob->set_skill("huanhua-shenfa", consider_lv(ob, 7));
	ob->set_skill("strike", consider_lv(ob, 7));
	ob->set_skill("feixu-zhang",consider_lv(ob, 7));
	ob->set_skill("dodge", consider_lv(ob, 7)); 
	ob->set_skill("sword", consider_lv(ob, 7)); 
	ob->set_skill("huanhua-jian", consider_lv(ob, 7)); 
	ob->set_skill("parry", consider_lv(ob, 7)); 
	ob->set_skill("literate", consider_lv(ob, 7));
	ob->set("shen",(me->query("combat_exp")/20));
	ob->move(environment(me));
	message_vision("\n" + HIW + "突然一条人影向$N扑了过来。\n"NOR, me);
	message_vision("\n" + HIR + "$n对$N大喝一声：“你这个权利帮的走狗，还不受死！”\n"NOR, me, ob);
	me->kill_ob(ob);
	ob->kill_ob(me);
	destruct(this_object());
}

int consider_lv(object ob,int a)
{
	int level; 
	float exper;

	exper = to_float(ob->query("combat_exp"));
	level = ceil( pow( exper*10.0, 0.333333) );

	level = level * a / 10;

	return level;
}
