// write by JackyBoy@CuteRabbit Studio for CCTX II 1999/5/17
// 主要增加了一些属性的修改以及配合电子邮件注册程序进行修改。

#define MAX_DUMMY 10
//定义可一同时登录的ID数

#include <ansi.h>
#include <command.h>
#include <login.h>
#include <runtime_config.h>
#include <mudlib.h>

inherit F_DBASE;

int wiz_lock_level = WIZ_LOCK_LEVEL;
int mad_lock = 0;
string *banned_name = ({
	"你", "我", "他", "她", "它",
	"时空",
});
void logon_main(string ,object );
void get_id(string , object );
void confirm_id(string , object );
object make_body(object );
void init_new_player(object );
varargs void enter_world(object , object , int );
varargs void reconnect(object , object , int );
object find_body(string );
int check_legal_id(string );
int check_legal_name(string );

void random_gift(mapping my)
{
	int i;
	int tmpstr, tmpint, tmpcon, tmpdex, tmpbac;
	tmpstr = tmpint = tmpcon = tmpdex = tmpbac = 10;

	for (i = 0; i < 50; i++) {
		switch (random(5)) {
		case 0: tmpstr++; break;
		case 1: tmpint++; break;
		case 2: tmpcon++; break;
		case 3: tmpdex++; break;
		case 4: tmpbac++; break;
		}
	}
	if (tmpstr <= 30) my["str"] = tmpstr; else my["str"] = 30;
	if (tmpint <= 30) my["int"] = tmpint; else my["int"] = 30;
	if (tmpcon <= 30) my["con"] = tmpcon; else my["con"] = 30;
	if (tmpdex <= 30) my["dex"] = tmpdex; else my["dex"] = 30;
	if (tmpbac <= 30) my["bac"] = tmpbac; else my["bac"] = 30;

	my["kar"] = 10 + random(21);
	my["per"] = 10 + random(21);
	my["apt"] = 20 + random(30);
}

void create() 
{
	seteuid(getuid());
	set("channel_id","连线精灵");
}

void logon(object ob)
{
	write("\n\nWelcome to SnowMud! Select GB or BIG5 (gb/big5):");
	input_to( (: logon_main :),ob);
}

void logon_main(string arg,object ob)
{
	object *usr;
	int i, wiz_cnt, ppl_cnt, login_cnt,i_user,log_num=0;
	string user_num;   
	int encode;
	if(!arg || arg=="")
	{
		write("\nSelect 国标码 GB or き絏 BIG5 (gb/big5):");
		input_to( (: logon_main :), ob );
		return;
	}
	else
	if(arg[0..0]=="g" || arg[0..0]=="G")
		encode=0;
	else
	if(arg[0..0]=="b" || arg[0..0]=="B")
		encode=1;
	else 
	{
		write("\nSelect 国标码 GB or き絏 BIG5 (gb/big5):");
		input_to( (: logon_main :), ob );
		return;
	}
	if(encode==0)
		write("\nUse GB encoded Chinese.\n");
	else
		write("\nUse BIG5 encoded Chinese.\n");
	ob->set_encoding(encode);
	if( mad_lock == 1 ) 
	{
		write("现在时空已经封闭了，不能进入！！ \n");
		destruct(ob);
		return;
	}
	if (BAN_D->is_banned(query_ip_name(ob)) == 1) 
	{
		write("你的地址在本 MUD 不受欢迎。\n");
		destruct(ob);
		return;
	}
	write(read_file(WELCOME)+BBLK+HIW);
	UPTIME_CMD->main();
	usr = users();
	wiz_cnt = 0;
	ppl_cnt = 0;
	login_cnt = 0;
	for(i=0; i<sizeof(usr); i++)
	{
		if( !environment(usr[i]) ) login_cnt++;
   		else 
		if( wizardp(usr[i]) )
		{
			if(usr[i]->query("env/invisibility")==0)
				wiz_cnt++;
		}
		else ppl_cnt++;
	}
	user_num=read_file(USERS,1);
	i_user=atoi(user_num);
	write(sprintf(BBLK+HIW"自一九九九年十一月十二日起，"+CHINESE_MUD_NAME+"共有%s人次来访。\n",chinese_number(i_user)));
	i_user=i_user+1; 
	user_num=sprintf("%d", i_user); 
	write_file(USERS,user_num,1);
	user_num=read_file(IDUSER,1);
	i_user=atoi(user_num);
	write(sprintf(CHINESE_MUD_NAME+"目前共有%s个注册玩家。\n",chinese_number(i_user))); 
	//这里应该统计分站人数
	//由于DNS_MASTER没有能及时反应其他游戏里的人数，所以暂时不进行处理
	write(sprintf("目前共有 %d 位巫师、%d 位玩家在线上，以及 %d 位使用者尝试连线中。\n\n",
		wiz_cnt, ppl_cnt, login_cnt ));
	for(i=0;i<sizeof(usr);i++) 
	if (ob!=usr[i]) 
		if 
		(
			(
				//这里设置一些特别允许的可以不限制的站点(必须是有固定IP的站点)
				query_ip_number(ob)!="10.163.180.3"&&
				query_ip_number(ob)!="10.163.179.201"&&
				query_ip_number(ob)!="10.163.180.4"&&
				query_ip_number(ob)!="10.163.180.2"
			)
			&&
				query_ip_name(ob)==query_ip_name(usr[i])
		) 
			log_num++;
	if (log_num >= MAX_DUMMY )
	{  
		write(HIR+"你只允许同时登陆"+MAX_DUMMY+"个IP，请退出其他帐号再试。\n"+NOR); 
		destruct(ob); 
		return;                 
	}
	else
	{
		write(HIW+"您所在的地址("+HIR+query_ip_number(ob)+HIW")已有"HIY+chinese_number(log_num)+HIW"位玩家在线上。\n");
	}
	write("您的英文名字：");
	input_to( (: get_id :), ob );
}

void get_id(string arg, object ob)
{
	object ppl;
	object *usr;
	int i, wiz_cnt;
	arg = lower_case(arg);
	if( !check_legal_id(arg)) 
	{
		write("您的英文名字：");
		input_to("get_id", ob);
		return;
	}

	usr = users();
	wiz_cnt = 0;
	for(i=0; i<sizeof(usr); i++) 
	{
		if( wizardp(usr[i]) ) 
			wiz_cnt++;
	}
	if( (string)SECURITY_D->get_status(arg)=="(player)"
		&& (sizeof(users()) - wiz_cnt) >= 150) 
	{
		ppl = find_body(arg);

		if( !ppl || !interactive(ppl) ) 
		{
			write("对不起，"+CHINESE_MUD_NAME+"的使用者已经太多了，请待会再来。\n");
			destruct(ob);
			return;
		}
	}

	if( wiz_level(arg) < wiz_lock_level ) 
	{
		write("对不起，"+CHINESE_MUD_NAME+"目前限制巫师等级 " + WIZ_LOCK_LEVEL
			+ " 以上的人才能连线。\n");
		destruct(ob);
		return;
	}
        
	if( (string)ob->set("id", arg) != arg ) 
	{
		write("无法正常设置用户名。\n");
		destruct(ob);
		return;
	}

	if( arg=="guest" ) 
	{
		// If guest, let them create the character.
		confirm_id("Yes", ob);
		return;
	} 
	else 
	if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 0 ) 
	{
		if( ob->restore() ) 
		{
			write("这个名字已经有人注册了，请输入密码：");
			input_to("get_passwd", 1, ob);
			return;
		}
		write("您的人物储存档出了一些问题，请利用guest(口令:guest)人物通知巫师处理。\n");
		destruct(ob);
		return;
	}
	write("使用 " + (string)ob->query("id") + " 这个名字将会创造一个新的人物，您确定吗(y/n)？");
	ob->set("newbie",1);
	input_to("confirm_id", ob);
}

void get_passwd(string pass, object ob)
{
	string my_pass,temp_pass;
	object user;
	int time_rl;
	string temps;
	write("\n");
	my_pass = ob->query("password");
	temp_pass= ob->query("temp_password");
	//temp_password属性是玩家初次注册时使用的临时密码
	if(my_pass&&my_pass==crypt(pass,my_pass))
	{
		//这时说明注册成功，设置注册属性
		ob->set("registered",1);
	}
	else
	if(	crypt(pass, temp_pass) != temp_pass ) 
	{
		write("密码错误！\n");
		destruct(ob);
		return;
	}
	else
	{
		//试为遗忘密码处理
		//所以设置登录到注册室！
		ob->set_temp("go_reg_room",1);
	}
	
	time_rl = time() - ob->query("last_on");
	// Check if logout recently
	if (time_rl >= 0 && time_rl <= 10)
	{
		temps = sprintf("你距上次退出仅 %d tick.\n", time_rl);
		write(temps);
		if ((string)SECURITY_D->get_status(ob->query("id")) == "(player)")
		{
			write("对不起，为了降低系统负荷，请稍后再login，多谢您的合作。\n");
	                destruct(ob);
	                return;
		} 
		else
		{
			write("虽然你是巫师，也不要频繁的login哦。\n");
		}
	}

	// Check if we are already playing.
	user = find_body(ob->query("id"));

	// by Find.
	if(user && !environment(user)) /* 这种状态是不应出现的 */
		destruct(user);

	if (user) 
	{
		if( user->query_temp("netdead") ) 
		{
			reconnect(ob, user);
			return;
		}
		write("您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)");
		input_to("confirm_relogin", ob, user);
		return;
	}

	if( objectp(user = make_body(ob)) ) 
	{
		if( user->restore() ) 
		{
			log_file( "USAGE", sprintf("%s loggined from %s (%s)\n", user->query("name"),
				query_ip_name(ob), ctime(time()) ) );
			enter_world(ob, user);
			return;
		} 
		else 
		{
			destruct(user);
		}
	}
	write("请您重新创造这个人物。\n");
	confirm_id("y", ob);
}

void confirm_relogin(string yn, object ob, object user)
{
	object old_link;

	if( yn=="" ) 
	{
		write("您要将另一个连线中的相同人物赶出去，取而代之吗？(y/n)");
		input_to("confirm_relogin", ob, user);
		return;
	}       
	if( yn[0]!='y' && yn[0]!='Y' ) 
	{
		write("好吧，欢迎下次再来。\n");
		destruct(ob);
		return;
	} 
	else
	{
		tell_object(user, "有人从别处( " + query_ip_number(ob)
			+ " )连线取代你所控制的人物。\n");
		log_file( "USAGE", sprintf("%s replaced by %s (%s)\n", user->query("name"),
			query_ip_name(ob), ctime(time()) ) );
	}
	// Kick out tho old player.
	old_link = user->query_temp("link_ob");
	if( objectp(old_link) )
	{
		exec(old_link, user);
		destruct(old_link);
	}
	reconnect(ob, user);    
}

void confirm_id(string yn, object ob)
{
	if( yn=="" )
	{
		write("使用这个名字将会创造一个新的人物，您确定吗(y/n)？");
		input_to("confirm_id", ob);
		return;
	}       
	if( yn[0]!='y' && yn[0]!='Y' )
	{
		write("好吧，那么请重新输入您的英文名字：");
		input_to("get_id", ob);
		return;
	}
	write( @TEXT
请输入您的高姓大名，由于这个名字代表你的人物，而且以后不能更改，
务必慎重择名（不雅观的姓名将被删除）。
(除了名字之外，本 mud 有许多取绰号、别称的设计，所以郑重建议您
 取一个比较像名字的中文名字。)
 另：请不要选择温瑞安小说中已有人物姓名。
TEXT
	);
	write("您的中文名字：");
	input_to("get_name", ob);
}

void get_name(string arg, object ob)
{
	if( !check_legal_name(arg) )
	{
		write("您的中文名字：");
		input_to("get_name", ob);
		return;
	}
	printf("%O\n", ob);
	ob->set("name", arg);
	write("请设定您的临时密码：");
	input_to("new_password", 1, ob);
}

void new_password(string pass, object ob)
{
	write("\n");
	if( strlen(pass)<5 )
	{
		write("密码的长度至少要五个字符，请重设您的临时密码：");
		input_to("new_password", 1, ob);
		return;
	}
	ob->set("temp_password",crypt(pass,0) );//新用户注册，设置临时口令
	write("请再输入一次您的临时密码，以确认您没记错：");
	input_to("confirm_password", 1, ob);
}

void confirm_password(string pass, object ob)
{
	mapping my;
	string old_temp_pass;
	write("\n");
	old_temp_pass=ob->query("temp_password");
	if( crypt(pass, old_temp_pass)!=old_temp_pass)
	{
		write("您两次输入的密码并不一样，请重新设定一次密码：");
		input_to("new_password", 1, ob);
		return;
	}
	write(@TEXT
一个人物的天赋对于他或她所修习的武艺息息相关。小雪初晴中的人物大多具
有以下五项天赋（另有福缘、容貌、资质为隐含天赋，随机产生）：
      +-----------------------------------------------------+
      | 膂力：影响攻击能力及负荷量的大小。                  |
      | 悟性：影响学习武功秘籍的速度及理解师傅的能力。      |
      | 根骨：影响体力恢复的速度及升级后所增加的气息、精力。|
      | 身法：影响命中率、防御及躲避的能力。                |
      | 毅力：影响影响可控的杀气数和斗志的损失和恢复速度。  |
      +-----------------------------------------------------+
TEXT);
	my = ([]);
	random_gift(my);
	printf("\n膂力[%d]，悟性[%d]，根骨[%d]，身法[%d]，毅力[%d]\n",
		my["str"], my["int"], my["con"], my["dex"], my["bac"]);
	write("您同意这一组天赋吗？");
	input_to("get_gift", ob, my);
}

void get_gift(string yn, object ob, mapping my)
{
	if (yn[0] != 'y' && yn[0] != 'Y') 
	{
		random_gift(my);
		printf("\n膂力[%d]，悟性[%d]，根骨[%d]，身法[%d]，毅力[%d]\n",
			my["str"], my["int"], my["con"], my["dex"], my["bac"]);
		write("您同意这一组天赋吗？");
		input_to("get_gift", ob, my);
	}
	write("您要扮演男性(m)的角色或女性(f)的角色？");
	input_to("get_gender", ob, my);
}

void get_gender(string gender, object ob, mapping my)
{	
	object user;
	ob->set("body", USER_OB);
	if( !objectp(user = make_body(ob)) )
		return;
	user->set("str", my["str"]);
	user->set("dex", my["dex"]);
	user->set("con", my["con"]);
	user->set("int", my["int"]);
	user->set("bac", my["bac"]);
	write("\n");
	if( gender=="" )
	{
		write("您要扮演男性(m)的角色或女性(f)的角色？");
		input_to("get_gender", ob,my);
		return;
	}
	if( gender[0]=='m' || gender[0]=='M' )
		user->set("gender", "男性");
	else if( gender[0]=='f' || gender[0]=='F' )
		user->set("gender", "女性" );
	else
	{
		write("对不起，您只能选择男性(m)或女性(f)的角色：");
		input_to("get_gender", ob,my);
		return;
	}
	//删除正在登录标志，该标志在/clone/user/login.c里设置！
	//涉及到/feature/save.c
	log_file( "USAGE", sprintf("%s was created from %s (%s)\n", user->query("id"),
		query_ip_name(ob), ctime(time()) ) );
	init_new_player(user);
	enter_world(ob, user);
	write("\n");
}

object make_body(object ob)
{
	string err;
	object user;
	
	user = new(ob->query("body"));
	if(!user)
	{
		write("现在可能有人正在修改使用者物件的程式，无法进行复制。\n");
		write(err+"\n");
		return 0;
	}
	seteuid(ob->query("id"));
	export_uid(user);
	export_uid(ob);
	seteuid(getuid());
	user->set("id", ob->query("id"));
	user->set_name( ob->query("name"), ({ ob->query("id")}) );
	return user;
}

void init_new_player(object user)
{
	user->set("title", "普通百姓");
	user->set("birthday", time() );
	user->set("newbie",1);
//    user->set("potential", 99)
	user->set("potential", 99);
	user->set("channels", ({ "chat", "rumor", "es", "new" ,"snow","party"}) );

}

                
varargs void enter_world(object ob, object user, int silent)
{
	object cloth, mailbox;
	string startroom;
	object login_ob;
	//从login_ob继承GB&BIG5解码方式
	user->set_encoding(ob->query_encoding());
	ob->delete_temp("loging");
	//必须有这句，否则ob->query_temp("link_ob")会在time_out后清零导致无法更新玩家！
	user->set_temp("link_ob", ob);
	ob->set_temp("body_ob", user);
	user->set("registered",ob->query("registered"));
	exec(user, ob);
	write("\n目前权限：" + wizhood(user) + "\n");
	//由于系统总是莫名其妙地将link_ob清0，因此在这里备份link_ob!
	if(objectp(ob))
		user->set_temp("link_ob1",ob);
	else
		write("link_ob不正确，请重新连线进入游戏！\n");
	
	user->setup();
	if (!user->query("food") && !user->query("water") && ob->query("age") == 14)
	{
		user->set("food", user->max_food_capacity());
		user->set("water", user->max_water_capacity());
	}
	// In case of new player, we save them here right aftre setup 
	// compeleted.
	user->save();
	ob->save();
	cloth = new("/clone/misc/cloth");
	cloth->move(user);
	cloth->wear();

// Give user a mailbox.
// Modified by Hop at 1997.04.10
	mailbox = new("/clone/misc/mailbox");
	mailbox->move(user);

// End of modification
	if( !silent )
	{
		write(read_file(MOTD));
		write("  \n"NOR);
		if( user->query("new_mail") )
		{
			tell_object(user, BLINK+HIY + "\n有您的信！快看你的信箱吧！\n\n" + NOR);
			user->set("new_mail", 0);
		}
		if( !user->is_ghost()&&user->query("newbie")&&!ob->query("registered"))
		{
			//如果是新手没有注册过，则先到注册处注册。
			write("哟！是新玩家哟，请先注册您的电子信箱吧！\n");
			startroom = NEW_PLAYER_START;
		}
		else
		if( user->is_ghost() )
		{
			startroom = DEATH_ROOM;
		}
		else
		if( !stringp(startroom = user->query("startroom")))
		{
			write("呀！不知道你应该从什么地方登录，先到注册处吧！\n");
			startroom = NEW_PLAYER_START;
		}
		/*if(ob->query_temp("go_reg_room"))
		{
			//如果输入了临时口令，则进入注册室！
			write("您输入了备用口令，将直接进入注册室！\n");
			startroom = NEW_PLAYER_START;
			ob->delete_temp("go_reg_room");
		}*/
		//巫师必须先到休息室报到
		if ( wiz_level( user->query("id") ) > 1 )
		{
			user->move(WIZ_START_ROOM);
			CHANNEL_D->do_channel( user, "wiz*",
			sprintf("连线进入"+CHINESE_MUD_NAME+"。") );
		}
		else
		{
			//因为需要取消注册处登录，所以临时增加句
			if(stringp(user->query("startroom")))
				startroom=user->query("startroom");
			if( !catch(load_object(startroom)) )
				user->move(startroom);
			else
			{
				user->move(START_ROOM);
				startroom = START_ROOM;
				user->set("startroom", START_ROOM);
			}
			tell_room(startroom, user->query("name") + "连线进入这个世界。\n",({user}));
		}
	}
	login_ob=new(LOGIN_OB);
	login_ob->set("id",user->query("id"));
	login_ob->restore();
	write("你上次连线是从" + HIR +login_ob->query("last_from") + NOR + " on " + 
		HIR +ctime(login_ob->query("last_on"))+ NOR + "\n");
	destruct(login_ob);
	CHANNEL_D->do_channel( this_object(), "sys",
		sprintf("%s由%s连线进入。["+CHINESE_D->chinese_time(6,ctime(time()))+"]", 
			user->name()+"("+user->query("id")+")", query_ip_name(user)) );
	if(!(wizardp(user)&&!user->query("env/logchat")))
		CHANNEL_D->do_channel( this_object(), "chat",
			sprintf("欢迎%s连线进入江湖。["+CHINESE_D->chinese_time(6,ctime(time()))+"]", 
			user->name()+"("+user->query("id")+")"));
	UPDATE_D->check_user(user);
	if( user->query("lastChangeSize") != file_size("/doc/help/change") ) 
	{
		user->set("lastChangeSize", file_size("/doc/help/change"));
		write(BLINK HIW"\n小雪初晴最新更新！！！请 help change 了解详细情况。\n\n"NOR);
	}
//检查是否进入排行榜！add by jackyboy@cctx 1999/3/8
	TOPTEN_D->topten_checkplayer(user);
//记录连线时的exp和time add by jackyboy@cctx 1999/3/8
	user->set_temp("temp_exp",user->query("combat_exp"));
	user->set_temp("temp_time",time());
}

varargs void reconnect(object ob, object user, int silent)
{
	user->set_temp("link_ob", ob);
	//多留一份备份！
	user->set_temp("link_ob1",ob);
	//另外如果link_ob里有"loging"这个temp变量应该删除才对！
	//否则ob就会在time_out后被清0！
	ob->delete_temp("loging");
	ob->set_temp("body_ob", user);
	exec(user, ob);
	user->reconnect();
	if( !silent )
	{
		tell_room(environment(user), user->query("name") + "重新连线回到这个世界。\n",
			({user}));
	}
	CHANNEL_D->do_channel( this_object(), "sys",
		sprintf("%s由%s重新连线进入。", user->query("name")+"("+user->query("id")+
			")", query_ip_name(user)) );
	UPDATE_D->check_user(user);
}

int check_legal_id(string id)
{
	int i,j;
	string *bad_word=({"fuck","shit","sex","father","mother"});
	i = strlen(id);
	if( (strlen(id) < 3) || (strlen(id) > 10 ) )
	{
		write("对不起，你的英文名字必须是 3 到 10 个英文字母。\n");
		return 0;
	}
	while(i--)
	{
		if( id[i]<'a' || id[i]>'z' )
		{
			write("对不起，你的英文名字只能用英文字母。\n");
			return 0;
		}
		//禁止连续4个字母相同
		if((i+3)<(sizeof(id)))
		{
			if(id[i]==id[i+1]&&id[i]==id[i+2]&&id[i]==id[i+3])
			{
				printf("对不起，游戏不允许ID中连续4个字母(%c)相同！\n",id[i]);
				return 0;
			}
		}
	}
	for(j=0;j<sizeof(bad_word);j++)
		if(strsrch(id,bad_word[j])!=-1)
		{
			write("对不起，请不要用含着"HIY+BLINK+bad_word[j]+NOR"这样的ID！\n"+
				"如果你确实要使用该ID，请与巫师联系！\n");
			return 0;
		}
	return 1;
}

int check_legal_name(string name)
{
	int i,j;
	string *bad_word=({"爸","妈","姨","妓","爷","奶","胖胖","婆","公",
        "操","日", "山猫"});
	i = strlen(name);
	if( (strlen(name) < 2) || (strlen(name) > 8 ) )
	{
		write("对不起，你的中文名字必须是 1 到 4 个中文字。\n");
		return 0;
	}
	while(i--)
	{
		if( name[i]<=' ' )
		{
			write("对不起，你的中文名字不能用控制字元。\n");
			return 0;
		}
		if( i%2==0 && !is_chinese(name[i..<0]) )
		{
			write("对不起，请您用「中文」取名字。\n");
			return 0;
		}
	}
	for(j=0;j<sizeof(bad_word);j++)
		if(strsrch(name,bad_word[j])!=-1)
		{
			write("对不起，请不要用含着"HIY+BLINK+bad_word[j]+NOR"这样的名字！\n"+
				"如果你确实要使用该名字，另起一个名字进入后请巫师来修改！\n");
			return 0;
		}
	if( member_array(name, banned_name)!=-1 )
	{
		write("对不起，这种名字会造成其他人的困扰。\n");
		return 0;
	}
	return 1;
}

object find_body(string name)
{
	object ob, *body;
	if( objectp(ob = find_player(name)) )
		return ob;
	body = children(USER_OB);
	for(int i=0; i<sizeof(body); i++)
	if( clonep(body[i])&&getuid(body[i]) == name )
		return body[i];
	return 0;
}

int set_wizlock(int level)
{
	if( wiz_level(this_player(1)) <= level )
		return 0;
	if( geteuid(previous_object()) != ROOT_UID )
		return 0;
	wiz_lock_level = level;
	return 1;
}

int set_madlock(int setmark)
{
	if( wiz_level(this_player(1)) < wiz_level("(hufa)") )
		return 0;
	if( setmark == 1 )
		mad_lock = 1;
	else
		mad_lock = 0;
	return 1;
}

int get_madlock()
{
	return mad_lock;
}




