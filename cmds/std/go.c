// go.c
#include <ansi.h>
inherit F_CLEAN_UP;

mapping default_dirs = ([
	"north":		"北",
	"south":		"南",
	"east":			"东",
	"west":			"西",
	"northup":		"北边",
	"southup":		"南边",
	"eastup":		"东边",
	"westup":		"西边",
	"northdown":	"北边",
	"southdown":	"南边",
	"eastdown":		"东边",
	"westdown":		"西边",
	"northeast":	"东北",
	"northwest":	"西北",
	"southeast":	"东南",
	"southwest":	"西南",
	"up":			"上",
	"down":			"下",
	"enter":		"里",
	"out":			"外",
]);


mapping reverse_dir=([
	"north":		"南面",
	"south":		"北面",
	"east":		"西面",
	"west":		"东面",
	"northup":		"南边",
	"southup":		"北边",
	"eastup":		"西边",
	"westup":		"东边",
	"northdown":	"南边",
	"southdown":	"北边",
	"eastdown":		"西边",
	"westdown":		"东边",
	"northeast":	"西南方向",
	"northwest":	"东南方向",
	"southeast":	"西北方向",
	"southwest":	"东北方向",
	"up":			"下面",
	"down":		"上面",
	"enter":		"外面",
	"out":		"里面",
]);


void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string dest, mout, min, dir,dir1,str,str1,face,thing_msg;
	object env, obj,che,thing;
	mapping exit;
	object *f_obs, *ob;
	int count = 0, my_dex, i,n,i_env,i_obj;

	if( !arg ) return notify_fail("你要往哪个方向走？\n");

	if( me->over_encumbranced() )
		return notify_fail("你的负荷过重，动弹不得。\n");
	if( me->is_busy() )
		return notify_fail("你的动作还没有完成，不能移动。\n");
	if (me->is_fighting()) {
		f_obs = me->query_enemy();
		if (objectp(f_obs[0]))
		if (5 + random((int)me->query("dex")) <= random((int)f_obs[0]->query("dex")))
		{
			me->start_busy(1);
//added by King
			message_vision("$N见势不好，转身要走，被$n一把拦在面前。想走？没那么容易！\n", me, f_obs[0]);
//end of appendence
			return notify_fail("你逃跑失败。\n");
		}
	}

	env = environment(me);
	if(!env) return notify_fail("你哪里也去不了。\n");

	if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
		if( query_verb()=="go")
			return notify_fail("这个方向没有出路。\n");
		else
			return 0;
	}

	dest = exit[arg];
	if( !objectp(obj = find_object(dest)) )
		obj=load_object(dest);
	if( !objectp(obj) )
		return notify_fail("无法移动。\n");

// Added by Hop
	ob = all_inventory(obj);
	for(i=0; i<sizeof(ob); i++)
		if( living(ob[i]) && ob[i] != me )
			count++;
	my_dex = (int)me->query_dex();
	if(((my_dex < 15) && (count > 8))
	|| ((my_dex < 20) && (count > 10))
	|| ((my_dex < 30) && (count > 12))
	|| ((my_dex < 40) && (count > 14)))
		return notify_fail("前面人太多了，你怎么挤也挤不过去。\n");
// End of appendence	
 
	if( !env->valid_leave(me, arg) ) return 0;

	if( !undefinedp(default_dirs[arg]) )
		dir = default_dirs[arg];
	else
		dir = arg;
	if( !undefinedp(reverse_dir[arg]) )
		dir1="从"+reverse_dir[arg];
	else dir1="不知道从哪里";

//以下是关于白天和黑夜显示的区别

	n=NATURE_D->night();
	i_env=(int)env->query("outdoors");
	i_obj=(int)obj->query("outdoors");
	
	if (!n) i=1;
	if (!i_env && !i_obj) i=1;
	if (n && i_env && !i_obj) i=2;
	if (n && ! i_env && i_obj) i=3;
	if (n && i_env && i_obj ) i =4;
	if( me->is_fighting() ) 
	{
		str="跌跌撞撞地跑了过来，模样有些狼狈。\n";
	 	str1="往" + dir + "落荒而逃了。\n";
	}
	else
	{
		str=dir1+"走了过来。\n";str1="往" + dir + "离开。\n";
	}

	switch( i)
	{	case 1 : 
		mout = me->name() ;
		min = me->name() ;
		break;
		case 2 :
		if(me->query("gender") == "女性")
		{
		mout = "一条倩影" ;
		min =  me->name() ;
		}
		else
		{
		mout = "一条黑影" ;
		min  = me->name() ;
		}
		break;	
		case 3 :
		if(me->query("gender") == "女性")
		{
		mout = me->name() ;
		min =  "一条倩影" ;
		}
		else
		{
		mout = me->name() ;
		min  = "一条黑影" ;
		}
		break;
		case 4 :
			if(me->query("gender") == "女性")
		{
		mout = "一条倩影" ;
		min =  "一条倩影" ;
		}
		else
		{
		mout = "一条黑影" ;
		min  = "一条黑影" ;
		}
	}
	if(!mout)
		mout=me->name();
	if(!min)
		min=me->name();
	face="";
	if (me->query("gender")=="女性")
	{
		if (me->query("per") >= 30) face ="娇艳绝伦" ;
		if ((me->query("per") >= 28) && (me->query("per") < 30)) face= "清丽绝俗" ;
		if ((me->query("per") >= 26) && (me->query("per") < 28)) face= "风情万种" ;
		if ((me->query("per") >= 24) && (me->query("per") < 26)) face= "容色秀丽" ;
		if ((me->query("per") >= 21) && (me->query("per") < 24)) face= "面目姣好" ;
		if (me->query("str") <= 16) face = "亭亭玉立" ;
		if ((me->query("str") <= 20) && (me->query("str") > 16)) face= "体态轻盈";
		if ((me->query("per")<21) && (me->query("str")>20) || !userp(me)) face = "";
	}
	else
	{
		if (me->query("per") >= 30) face= "玉树临风般" ;
		if ((me->query("per") >= 26) && (me->query("per") < 30)) face="英俊潇洒" ;
		if ((me->query("per") >= 22) && (me->query("per") < 26)) face="仪表堂堂" ;
		if (me->query("str") >=23) face = "身材壮硕" ;
		if ((me->query("str") >= 20) && (me->query("str") < 23)) face= "膀大腰圆";
		if ((me->query("per")<22) && (me->query("str")<20) || !userp(me)) face = "";
	}
	if(face&&face!="")
		face+="的";
	if (objectp(thing = me->query_temp("armor/cloth")))
		thing_msg = "身着" + thing->query("name");
	else
		thing_msg = "全身光溜溜";
	if (objectp(thing = me->query_temp("weapon")))
		thing_msg += "手执" + thing->query("name");
	if ( me->query("race") == "野兽")
	{
		mout = me->name() + "呼地往" + dir + "一窜就消失了。\n";
		min = me->name() + "呼地窜了出来，警惕地四周张望着。\n";
	}
	else
	{
		if ( me->query_temp("xueheche") && (che=present("xuehe che",environment(me))))
		{
			mout = mout+"驾着血河车向" + dir + "疾驰而去。\n";
			min = face + min + thing_msg + "驾着血河车轰隆隆的开了过来。\n";
			che->move(obj);
		}
		else
		{
			mout = mout + "往" + dir + "离开。\n";
			min = face + min + thing_msg + "走了过来。\n";
		}
	}

	message( "vision", mout, environment(me), ({me}) );
	//view_message(mout,environment(me),me);
	if( me->move(obj) )
	{
		me->remove_all_enemy();
		message( "vision", min, environment(me), ({me}) );
		if (me->query_temp("xueheche") && (present("xuehe che",obj))) 
		{
			message_vision(HIR"刹那间，这里充满了一种红红的血光。空气里顿时洋溢着一股浓浓的杀气。\n"NOR,me);
		}
		me->set_temp("pending", 0);
		all_inventory(env)->follow_me(me, arg);
		if (!me->is_ghost())
			me->add("jingli", -1);
		return 1;
	}

	return 0;
}

void do_flee(object me)
{
	mapping exits;
	string *directions;

	if( !environment(me) || !living(me) ) return;
	exits = environment(me)->query("exits");
	if( !mapp(exits) || !sizeof(exits) ) return;
	directions = keys(exits);
	tell_object(me, "看来该找机会逃跑了...\n");
	main(me, directions[random(sizeof(directions))]);
}

int help()
{
	write(@HELP
指令格式 : go <方向>
 
让你往指定的方向移动。
 
HELP
    );
    return 1;
}
