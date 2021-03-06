// moye.c  莫邪
// Written by Doing Lu  1998/11/2

// 莫邪可以回答 player 一些问题，并在接受定金后交给 player 一封信件 /d/item/obj/letter
// 每次见面需要清除询问过的标志，如果player没有询问过价格，不能交付定金，以免用户打造完粗坯
// 后没有能力支付，浪费了原料

// 如果 player 交给莫邪道具粗坯，莫邪提示你交钱，如果没有足够的钱，就把道具粗坯退给你
// 这个期间 player 设置临时变量 item/交付粗坯 = 1, item/value = 道具价格
// 莫邪设置临时变量 item/接受了粗坯 = 1，item/交付人ID = 交付人ID，item/粗坯 = 粗坯名称

// 如果 player 交付了足够的钱，清除旧的 item, 并且设置 item/准备接受 = 1
// 莫邪清除临时变量 item，并将粗坯交给干将，由干将设置莫邪的变量 item/正在炼制 = 1

// 干将炼制完道具后，等待用户输入一些信息，在此期间，清除用户的临时变量 item
// 改为设置临时变量 item/输入信息 = 1
// 同时清除莫邪的临时变量 item/正在炼制，改为设置莫邪的临时变量 item/正在等候 = 1
// 直到用户输入完毕或是因故中止，清除莫邪的临时变量 item

// 在莫邪设置了临时变量 item/正在炼制 和 item/正在等候 时，不接受 player 的物品

// 道具价格：power_point * scale / 2 * 5
// 道具有效点数：power_point * scale / 2，相当于道具价格 / 5
// 伤害力 = 有效点数 * (70 - 120)%，和炼道具者的耗费的内力有关

inherit NPC;

#include <ansi.h>

int	ask_me();
int	no_money();

void create()
{
	set_name("莫邪", ({ "moye", "mo" }));
	set("long", "她长得清美秀丽，一副不食人间烟火的模样。她就是铸剑大师干将的妻子。\n" );

	set("nickname", HIY "剑仙" NOR);
	set("gender", "女性");
	set("attitude", "friendly");

	set("age", 1525);
	set("shen_type", 0);
	
	set("str", 1000);			// 保证不会因为负荷过大而接受不了东西

	set("inquiry", ([
		"炼制" : (: ask_me :),
		"铸剑" : (: ask_me :),
		"炼剑" : (: ask_me :),
		"炼刀" : (: ask_me :),
		"炼杖" : (: ask_me :),
		"炼鞭" : (: ask_me :),
		"炼锤" : (: ask_me :),
		"炼棍" : (: ask_me :),
		"炼甲" : (: ask_me :),
		"打造" : (: ask_me :),
		"铸造" : (: ask_me :),
		"制造" : (: ask_me :),
		"打制" : (: ask_me :),
		"定制" : (: ask_me :),
		"定做" : (: ask_me :),
		"定造" : (: ask_me :),
		"兵器" : (: ask_me :),
		"道具" : (: ask_me :),
		"装备" : (: ask_me :),
		"武器" : (: ask_me :),
		"刀剑" : (: ask_me :),
		"装甲" : (: ask_me :),
		
		"没钱" : (: no_money :),
		"钱不够":(: no_money :),
		"等会" : (: no_money :),

		"原料" : "炼制道具可不能没有原料啊，要想炼制武器就得有玄铁石一类的东西。\n          要想炼制防具就得有天蚕丝那些东西。这些原料很难找，可遇不可求啊！\n",
		"配料" : "光有原料还打造不出最好的道具，如果有象麒麟之血那样配料就可以大大激发原料的潜力，\n          当然了，这根本就是神话里的东西，根本找不到的。其实象鸡血草一类的东西也是可以的哦。\n",
		"定金" : "定金很少，只需要五两黄金啦，不过交定金前先让我看看(show)材料，也好定价哦。\n",
		"价格" : "你把原料和配料给我看看(show)，我就能估摸出一个价钱。",
	]));

        setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	// 清除询问标志
	this_player()->delete_temp("query_moye");

	add_action("do_show", "show");
	if (! this_player()->query_temp("item/交付粗坯"))
	{
		remove_call_out("greeting");
		call_out("greeting", 1, this_player());
	} else
	{
		remove_call_out("greeting2");
		call_out("greeting2", 1, this_player());
	}
}

void greeting(object me)
{
	if (objectp(present(me, environment())))
	{
		message_vision("莫邪笑着对$N说：你好，你是想打造道具吗？要是炼好了粗坯请交给我。\n", me);
	}
}

void greeting2(object me)
{
	if (objectp(present(me, environment())))
	{
		message_vision("莫邪对$N说：快点交钱啊，要是没有就明说没钱嘛。\n", me);
	}
}

int do_show(string arg)
{
	object	me;
	object	ob1, ob2;
	string	mat1, mat2;
	string	msg;
	int	power_point, scale;
	int	value;
	int	n;

	me = this_player();
	if (!arg) return notify_fail("你想干什么，是要跳个舞么？\n");

	// 取原料，配料
	n = sscanf(arg, "%s %s", mat1, mat2);
	if (!n)
	{
		mat1 = arg;
		n = 1;
	}
	power_point = 0;
	scale = 0;

	// 取object1
	if (!objectp(ob1 = present(mat1, me)))
		return notify_fail("算了吧，你身上没有 " + mat1 + " 这种东西。\n");
	if (! ob1->query("material_attrib"))
	{
		message_vision("莫邪一愣，对$N说道：这种东西也能用来炼制，我没听说过。\n", me);
	}
	if (ob1->query("material_attrib") != "z")
	{
		// 不是配料
		power_point = ob1->query("power_point");
	} else
	{
		// 是配料
		scale = ob1->query("scale");
	}

	if (n == 2)
	{
		// 取object2
		if (!objectp(ob2 = present(mat2, me)))
			return notify_fail("算了吧，你身上没有 " + mat2 + " 这种东西。\n");
		if (! ob2->query("material_attrib"))
		{
			message_vision("莫邪一愣，对$N说道：这种东西也能用来炼制，我没听说过。\n", me);
			return 1;
		}
		if (ob2->query("material_attrib") != "z")
		{
			// 不是配料
			if (power_point !=0)
			{
				message_vision("莫邪摇头对$N道：对不起，我们没法将这两种原料混练，你应该拿种配料来。\n", me);
				return 1;
			}
			power_point = ob2->query("power_point");
		} else
		{
			// 是配料
			if (scale !=0)
			{
				message_vision("莫邪摇头对$N道：对不起，我们没法将这两种配料混练，你得拿种原料来。\n", me);
				return 1;
			}
			scale = ob2->query("scale");
		}
	} else
	{
		// 如果没有配料，scale设置成1 (相当于比例是0.5)
		scale = 1;
	}

	if (power_point == 0)
	{
		message_vision("莫邪仔细的看了看$N拿出的配料，说道：只用配料是打造不了道具的。\n", me);
		return 1;
	}
	value = scale * power_point * 5 / 2;
	if (n == 2)
		msg = sprintf("莫邪仔细的看了看$N拿出的原料和配料，说道：如果要用这种原料和配料打造兵器，\n" +
			"只需要%s两黄金，怎么样，我们价格很合理吧。要是没问题，请付五两黄金做定金。\n",
			chinese_number(value));
	else
		msg = sprintf("莫邪仔细看了看$N拿出的原料，说道：如果没有配料，只用这种原料打造道具，\n" +
			"只需要%s两黄金，怎么样，我们价格很合理吧。要是没问题，请付五两黄金做定金。\n",
			chinese_number(value));
	message_vision(msg, me);
	me->set_temp("query_moye", 1);

	return 1;
}

// 发出提示信息
int ask_me()
{
	message_vision("莫邪对$N说道：" 
		"你是要打造自己的道具吗？\n"
		"我们这里可以为你打造各种武器包括刀、剑、锤、鞭、杖和护甲，都是第一流的。\n"
		"你先把原料配料给我看看(show)，我先估算一下价钱，然后你交定金给我，我就让\n"
		"你去我们弟子那里先打造粗坯，然后回来付钱，再由我们精制，一定会让你满意的。\n"
		"当然了，我们可不负责给你找原料哦，只有你自己辛苦辛苦了。\n", this_player());
	return 1;
}

int no_money()
{
	object ob;
	object me;
	
	me = this_player();
	if (! this_object()->query_temp("item/接受了粗坯") ||
	      this_object()->query_temp("item/交付人ID") != me->query("id"))
	{
		message_vision("莫邪眼睛一瞪，对$N说道：没钱，你没钱关我啥事，我又不是财神爷。\n", me);
		return 1;
	}
	me->delete_temp("item");
	if (! objectp(ob = present(this_object()->query_temp("item/粗坯"), this_object())))
	{
		// 如果道具粗坯不存在，可能是系统故障
		message_vision("莫邪对$N说道：对不起，你的道具粗坯给我弄丢了...抱歉的啦...\n", me);
		this_object()->delete_temp("item");
		return 1;
	}
	this_object()->delete_temp("item");
	// 交还道具粗坯
	message_vision("莫邪对$N说道：你没有钱，那就算了，东西先还给你吧，不过它不精制是用不了的...\n"
		       "莫邪把粗坯还给了$N。\n", me);
	ob->move(me);
	return 1;
}

// 接受定金
int accept_object(object me, object ob)
{
	object letter;
	object ganjiang;
	object item_temp;
	string msg;
	int    val;
	if (this_object()->query_temp("item/正在炼制"))
	{
		message_vision("莫邪紧张的对$N说：别吵，干将正在干活呢。\n", me);
		return 0;
	}
	if (this_object()->query_temp("item/正在等候"))
	{
		message_vision("莫邪对$N说：别吵，干将正在和顾客谈话呢。\n", me);
		return 0;
	}
	
	if (ob->query("item_origin"))
	{
		// 接受粗坯
		if (this_object()->query_temp("item/接受了粗坯"))
		{
			// 如果已经接受了一个人道具粗坯，则拒绝接受
			message_vision("莫邪对$N说道：对不起，我先处理完这位客人的事再说。\n", me);
			return 0;
		}
		// 计算价值
		val = ob->query("mat_attr1") * ob->query("mat_attr2") * 5 / 2;
		msg = sprintf("莫邪对$N说道：很好，打造的不错，请您交钱吧，需要%s两黄金，交钱吧。\n",
				chinese_number(val));
		message_vision(msg, me);
		ob->set("point", val / 5);
		ob->set("value", val * 10000);
		if (wizardp(me))
		{
			message_vision("莫邪仔细看了看$N，笑着说道：原来是巫师，那么你随便给点好了。\n", me);
			val = 0;
		}
		me->set_temp("item/value", val * 10000);
		me->set_temp("item/交付粗坯", 1);
		this_object()->set_temp("item/接受了粗坯", 1);
		this_object()->set_temp("item/交付人ID", me->query("id"));
		this_object()->set_temp("item/粗坯", ob->query("id"));
		// 如果过一段时间没有交款，还道具粗坯
		remove_call_out("time_out");
		call_out("time_out", 30, me, ob);
		return 1;
	}
	if (ob->query("money_id"))
	{
 		if (me->query_temp("item/交付粗坯"))
 		{
 			// 如果是交付了粗坯就交款
 			if (this_object()->query_temp("item/交付人ID") != me->query("id"))
 			{
 				// 交付人和付款人对不上号
 				message_vision("莫邪一脸迷惑的对$N说道：你以前好象给过我道具粗坯啊，怎么我一点印象都没有了？\n", me);
 				me->delete_temp("item");
 				return 0;
 			}
 			if (ob->value() < me->query_temp("item/value"))
 			{
	 			message_vision("莫邪对$N说：对不起，本店开张一千年来，还没有打过折扣。\n", me);
				return 0;
			}
			message_vision("莫邪对$N说道：好，这就给你炼！\n", me);
			this_object()->delete_temp("item/接受了粗坯");
			me->delete_temp("item");
			remove_call_out("time_out");
			// 如果干将不在
			if (! objectp(ganjiang = present("ganjiang", environment())))
			{
				message_vision("莫邪看了看四周，不禁一呆，说道：干将呢？他不在，没办法做了...你改天再来吧。\n", me);
				command("give " + me->query("id") + this_object()->query_temp("item/粗坯"));
				this_object()->delete_temp("item");
				me->delete_temp("item");
				return 0;
			}
			if (! objectp(item_temp = present(this_object()->query_temp("item/粗坯"), this_object())))
			{
				message_vision("莫邪一呆，你的东西呢？我怎么招不着了！见鬼了。", me);
				this_object()->delete_temp("item");
				me->delete_temp("item");
				return 0;
			}
			// 交付道具给干将，用户准备接受
			me->set_temp("item/准备接受", 1);
			message_vision("莫邪把" + item_temp->query("name") + "交给了干将。\n", me);
			item_temp->move(ganjiang);
			ganjiang->start_work(me, item_temp);
			return 1;
 		}
 		// 交定金
		if (! me->query_temp("query_moye"))
		{
			message_vision("莫邪对$N笑道：这么急就交定金啊，先让我看看(show)原料配料，不然你没钱付可就浪费了。\n", me);
			return 0;
		}
 		if (ob->value() < 50000)
		{
			message_vision("莫邪对$N说：对不起，定金要五两黄金，本店开张一千年来，还没有打过折扣。\n", me);
			return 0;
		}
		message_vision("莫邪看了看$N给的定金，满意的说道：好，你拿这封信去找我们的弟子打造粗坯吧。\n"
			       "莫邪给了$N一封信。\n", me);
		letter = new("/d/item/obj/letter");
		letter->move(me);
		return 1;
	} else
	{
		message_vision("莫邪眼睛一瞪，对$N说道：你给我这些东西干什么？我不要！\n", me);
		return 0;
	}
}

int time_out(object me, object ob)
{
	// 过了一段时间 player 没有交款，退回粗坯
	if (! this_object()->query_temp("item/交付人ID")) return 1;
	me->delete_temp("item");
	this_object()->delete_temp("item");
	if (! objectp(me) || ! objectp(present(me, environment())))
	{
		// 没有这个 player, 或者这个 player 不在这里
		command("say 奇怪，刚才那位客人呢？怎么这就走了？\n");
		if (objectp(ob)) destruct(ob);
		return 1;
	}
	if (! objectp(ob) || ! objectp(present(ob, this_object())))
	{
		// 如果道具粗坯不存在，可能是系统故障
		message_vision("莫邪对$N说道：对不起，你的道具粗坯给我弄丢了...抱歉的啦...\n", me);
		return 1;
	}
	// 交还道具粗坯
	message_vision("莫邪对$N说道：看来你是没有钱了，东西先还给你吧，真是的，不精制是用不了的...\n"
		       "莫邪把粗坯还给了$N。\n", me);
	ob->move(me);
	return 1;
}
